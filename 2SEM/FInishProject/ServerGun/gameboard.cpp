#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
ui(new Ui::GameBoard),
networkSession(0),	
tcpServer(0),
clientSocket(0),
messageSize(0),
isGame(false)
{
	ui->setupUi(this);	
	ui->pushButton->setEnabled(false);
	setWindowTitle(tr("Зачётные пушки"));	
	ui->redLine->setReadOnly(true);
	ui->blueLine->setReadOnly(true);
	ui->redLine->setText("0");
	ui->blueLine->setText("0");	
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
	else
	{
		sessionOpened();
	}
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptedConnection()));        
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startGame()));
}

GameBoard::~GameBoard()
{
	delete ui;
	delete weapons;
	delete scene;
	delete networkSession;
	delete clientSocket;
	delete tcpServer;
}

void GameBoard::sessionOpened()
{
	if (networkSession)
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

	tcpServer = new QTcpServer(this);
	if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
	{
		QMessageBox::critical(this, tr("ScorpionServer"),
									tr("Unable to start the server: %1.")
									.arg(tcpServer->errorString()));
		close();
		return;
	}
	ui->portLabel->setText(tr("IP: %1 port: %2")
						.arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
}

void GameBoard::sendMessage(QString tmp)
{
	if(clientSocket)
	{
		QByteArray block;
		QDataStream out(&block, QIODevice::WriteOnly);
		out << (quint16)tmp.length();
		out << tmp;
		clientSocket->write(block);
	}
}

void GameBoard::acceptedConnection()
{
	clientSocket = tcpServer->nextPendingConnection();
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startReadMessage()));
	connect(clientSocket, SIGNAL(disconnected()), this, SLOT(makeDisconection()));
	connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));	
	ui->pushButton->setEnabled(true);
}

void GameBoard::startReadMessage()
{
	QDataStream in(clientSocket);
	in.setVersion(QDataStream::Qt_5_1);
	if (messageSize == 0)
	{
		if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
		return;
		in >> messageSize;
	}
	if (clientSocket->bytesAvailable() < messageSize)
		return;
	QString tmpMessage;
	in >> tmpMessage;	
	emit somethingChange(tmpMessage);
	messageSize = 0;
}

void GameBoard::makeDisconection()
{	
	ui->pushButton->setEnabled(false);
	QMessageBox::warning(this, tr("Warning!"), tr("Client has been disconnected"));
	delete weapons;
	delete scene;
	isGame = false;
}



void GameBoard::startGame()
{
	if (isGame)
		return;
	isGame = true;
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
