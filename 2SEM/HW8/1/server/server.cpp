#include <QMessageBox>
#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server),
    networkSession(0),	
    tcpServer(0),
    clientSocket(0),
    messageSize(0)
{
    ui->setupUi(this);      
        
    setWindowTitle(tr("ScorpionServer"));    
    ui->sendButton->setEnabled(false);    
    ui->conversation->setReadOnly(true);
    
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

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptedConnection()));        
}

Server::~Server()
{
    delete ui;
}

void Server::sessionOpened()
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

     ui->ipAndPort->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Client example now.")
                         .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
    
 }
 
void Server::sendMessage()
{
    if(clientSocket)
    {
        ui->sendButton->setEnabled(false);
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        QString tmp = ui->messageLine->text();
        ui->messageLine->clear();
        out << (quint16)tmp.length();
        out << tmp;
        clientSocket->write(block);
        ui->sendButton->setEnabled(true);
        ui->conversation->textCursor().insertText("You: " + tmp + '\n');        
    }
}


void Server::acceptedConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startReadMessage()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(makeDisconection()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    ui->sendButton->setEnabled(true);
}

void Server::startReadMessage()
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
    ui->conversation->textCursor().insertText("Client: " + tmpMessage + '\n');
    messageSize = 0;
}

void Server::makeDisconection()
{
    ui->sendButton->setEnabled(false);
    QMessageBox::warning(this, tr("Warning!"), tr("Client has been disconnected"));
}
