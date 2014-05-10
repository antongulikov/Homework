#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QtNetwork/QtNetwork>

namespace Ui {
class Client;
}

/// class for client
class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
/// open session
    void sessionOpened();
    void displayError(QAbstractSocket::SocketError socketError);
/// try to connect with server
    void tryConnect();    
/// send message to server
    void sendMessage();
/// read message from server
    void startReadMessage();
/// make disconection
    void makeDisconnection();
    void enableAddressChange();
    void disableAddressChange();

private:
    Ui::Client *ui;
    QTcpSocket *serverSocket;
    QNetworkSession *networkSession;
    quint16 messageSize;
    bool isConnected;
/// change enable for serverPort and serverNames
    void changeEnable(bool value);
};

#endif // CLIENT_H
