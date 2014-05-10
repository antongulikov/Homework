#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QtNetwork/QtNetwork>

namespace Ui {
class Server;
}

/// class for server
class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
/// open session
    void sessionOpened();
/// 
    void acceptedConnection();
/// read message from client
    void startReadMessage();
/// make disconection
    void makeDisconection();
/// send message to client
    void sendMessage();
    
private:
    Ui::Server *ui;
    QNetworkSession *networkSession;
    quint16 messageSize;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;    
};

#endif // SERVER_H
