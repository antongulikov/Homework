#include "client.h"
#include "ui_client.h"
#include <QMessageBox>

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client),
    networkSession(0),
    messageSize(0),
    isConnected(false)
{
    ui->setupUi(this);
    setWindowTitle(tr("ScorpionClient")); 
    
    ui->conversation->setReadOnly(true);           
            
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        ui->serverName->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->serverName->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        ui->serverName->addItem(QString("localhost"));
        
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (!ipAddressesList.at(i).isLoopback())
            ui->serverName->addItem(ipAddressesList.at(i).toString());
    }
    
    ui->serverPort->setValidator(new QIntValidator(1, 65535, this));
    
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
    
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));    
    
}

Client::~Client()
{
    delete ui;
}

void Client::sendMessage()
{
	ui->sendButton->setEnabled(false);
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    QString tmp = ui->messageLine->text();
    ui->messageLine->clear();
    out << (quint16)tmp.length();
    out << tmp;
    serverSocket->write(block);
    ui->sendButton->setEnabled(true);
    ui->conversation->textCursor().insertText("You: " + tmp + '\n');            
}


void Client::startReadMessage()
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
    messageSize = 0;
    QString tmpMessage;
    in >> tmpMessage;
    ui->conversation->textCursor().insertText("Server: " + tmpMessage + '\n');
}

void Client::sessionOpened()
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
    ui->sendButton->setEnabled((!networkSession || networkSession->isOpen())
								&& !ui->serverName->currentText().isEmpty()
								&& !ui->serverPort->text().isEmpty());
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    serverSocket->close();
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("ScorpionClient"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("ScorpionClient"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("ScorpionClient"),
                                 tr("The following error occurred: %1.")
                                 .arg(serverSocket->errorString()));
    }
    changeEnable(true);
}

void Client::makeDisconnection()
{
    ui->sendButton->setEnabled(false);
    changeEnable(true);
    QMessageBox::warning(this, tr("Warning!"), tr("You are disconnected"));
}

void Client::tryConnect()
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
    serverSocket->connectToHost(ui->serverName->currentText(), ui->serverPort->text().toInt());
    if (serverSocket->waitForConnected(5000))
    {
        ui->sendButton->setEnabled((!networkSession || networkSession->isOpen())
								&& !ui->serverName->currentText().isEmpty()
								&& !ui->serverPort->text().isEmpty());
        ui->connectButton->setText("Disconnect");
        isConnected = true;
    }
    else
    {
        QMessageBox::information(this, tr("ScorpionClient"), tr("Connection timed out"));
        changeEnable(true);
	}
}

void Client::changeEnable(bool value)
{
    ui->serverName->setEnabled(value);
    ui->serverPort->setEnabled(value);
}

void Client::enableAddressChange()
{
	changeEnable(true);	
}

void Client::disableAddressChange()
{
	changeEnable(false);	
}