#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
ui(new Ui::GameBoard),
networkSession(0),	
messageSize(0),
serverSocket(0),
weapons(0),
scene(0),
tcpServer(0),
isConnected(false)
{
	ui->setupUi(this);	
	setWindowTitle(tr("Зачётные пушки"));
	ui->redLine->setReadOnly(true);
	ui->blueLine->setReadOnly(true);
	ui->redLine->setText("0");
	ui->blueLine->setText("0");	

	QString name = QHostInfo::localHostName();
	if (!name.isEmpty())
	{
		ui->adressComboBox->addItem(name);
		QString domain = QHostInfo::localDomainName();
		if (!domain.isEmpty())
			ui->adressComboBox->addItem(name + QChar('.') + domain);
	}
	if (name != QString("localhost"))
		ui->adressComboBox->addItem(QString("localhost"));
	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	for (int i = 0; i < ipAddressesList.size(); ++i)
	{
		if (!ipAddressesList.at(i).isLoopback())
		ui->adressComboBox->addItem(ipAddressesList.at(i).toString());
	}
	ui->portEdit->setValidator(new QIntValidator(1, 65535, this));

	serverSocket = new QTcpSocket(this);    
	connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startReadMessage()));
	connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	connect(serverSocket, SIGNAL(disconnected()), this, SLOT(makeDisconnection()));
	connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));
	connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));

	QNetworkConfigurationManager manager;
	if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
	{
		QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
		settings.beginGroup(QLatin1String("QtNetwork"));
		const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
		settings.endGroup();        
		QNetworkConfiguration config = manager.configurationFromIdentifier(id);
		if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
		{
			config = manager.defaultConfiguration();
		}
		networkSession = new QNetworkSession(config, this);
		connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
		networkSession->open();
	}   

	connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));    


}

GameBoard::~GameBoard()
{
	delete ui;
	delete weapons;
	delete scene;
	delete networkSession;
	delete serverSocket;
}

void GameBoard::sessionOpened()
{
	QNetworkConfiguration config = networkSession->configuration();
	QString id;
	if (config.type() == QNetworkConfiguration::UserChoice)
		id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
	else
		id = config.identifier();
	QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
	settings.beginGroup(QLatin1String("QtNetwork"));
	settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
	settings.endGroup();
}

void GameBoard::displayError(QAbstractSocket::SocketError socketError)
{
	serverSocket->close();
	switch (socketError)
	{
		case QAbstractSocket::RemoteHostClosedError:
			break;
		case QAbstractSocket::HostNotFoundError:
			QMessageBox::information(this,  tr("ScorpionClient"),
											tr("The host was not found. Please check the "
												"host name and port settings."));
			break;
		case QAbstractSocket::ConnectionRefusedError:
			QMessageBox::information(this,  tr("ScorpionClient"),
											tr("The connection was refused by the peer. "
												"Make sure the fortune server is running, "
												"and check that the host name and port "
												"settings are correct."));
			break;
		default:
			QMessageBox::information(this,  tr("ScorpionClient"),
											tr("The following error occurred: %1.")
											.arg(serverSocket->errorString()));
	}
	changeEnable(true);
}


void GameBoard::sendMessage(QString tmp)
{
	if(serverSocket)
	{
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out << (quint16)tmp.length();
		out << tmp;
		serverSocket->write(block);
	}
}


void GameBoard::startReadMessage()
{
	QDataStream in(serverSocket);
	in.setVersion(QDataStream::Qt_5_1);
	if (messageSize == 0)
	{
		if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
		return;
		in >> messageSize;
	}
	if (serverSocket->bytesAvailable() < messageSize)
		return;
	QString tmpMessage;
	in >> tmpMessage;	
	emit somethingChange(tmpMessage);
	messageSize = 0;
}

void GameBoard::makeDisconnection()
{	
	changeEnable(true);
	QMessageBox::warning(this, tr("Warning!"), tr("Server has been disconnected"));
}

void GameBoard::tryConnect()
{
	if (isConnected)
	{
		ui->connectButton->setText("Connect");
		isConnected = false;
		serverSocket->close();
		return;
	}
	changeEnable(false);
	QMessageBox::information(this, tr("ScorpionClient"), tr("trying to connect"));
	serverSocket->connectToHost(ui->adressComboBox->currentText(), ui->portEdit->text().toInt());
	if (serverSocket->waitForConnected(5000))
	{
		isConnected = true;
	}
	else
	{
		QMessageBox::information(this, tr("ScorpionClient"), tr("Connection timed out"));
		changeEnable(true);
		return;
	}
	startGame();
}   

void GameBoard::changeEnable(bool value)
{
    ui->portEdit->setEnabled(value);
    ui->adressComboBox->setEnabled(value);
}

void GameBoard::enableAddressChange()
{
	changeEnable(true);	
}

void GameBoard::disableAddressChange()
{
	changeEnable(false);	
}

void GameBoard::startGame()
{
	ui->connectButton->setEnabled(false);
	scene = new QGraphicsScene(ui->graphicsView->x(), ui->graphicsView->y(), ui->graphicsView->width() - 10, ui->graphicsView->height() - 10, ui->graphicsView);	
	scene->setFocus();
	scene->setBackgroundBrush(Qt :: black);
	weapons = new Weapons(ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);
	weapons->setFocus();
	connect(weapons, SIGNAL(winner(int)), this, SLOT(changeScore(int)));	
	connect(this, SIGNAL(somethingChange(QString)), weapons, SLOT(opponentEvent(QString)));			
	connect(weapons, SIGNAL(playerEvent(QString)), this, SLOT(sendMessage(QString)));
	scene->addItem(weapons);	
	ui->graphicsView->setScene(scene);			
}

void GameBoard::changeScore(int player)
{
	switch(player)
	{
		case 0 :
		{
			int currentScore = getScore(ui->redLine->text().toStdString()) + 1;
			ui->redLine->setText(QString :: number(currentScore));
			break;
		}
		case 1 :
		{
			int currentScore = getScore(ui->blueLine->text().toStdString()) + 1;
			ui->blueLine->setText(QString :: number(currentScore));
			break;
		}
	}
}

int GameBoard::getScore(string s)
{
	int result = 0;
	for (int i = 0; i < (int) s.size(); i++)
	{
		result = result * 10 + (int)(s[i] - '0');
	}
	return result;
}
