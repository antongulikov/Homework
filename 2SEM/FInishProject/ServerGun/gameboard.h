#pragma once
#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <weapons.h>
#include <string>
#include <QtNetwork/QtNetwork>

using namespace std;

namespace Ui {
	class GameBoard;
}

class GameBoard : public QWidget
{
	Q_OBJECT
	
public:

	explicit GameBoard(QWidget *parent = 0);
	~GameBoard();
	
private slots:

    /// ������ ����
	void startGame();

	/// �������� ����� ����
	void changeScore(int player);
	void sessionOpened();
	void acceptedConnection();
	void startReadMessage();	
	void makeDisconection();

	/// �� ������� ���������
	void sendMessage(QString massege);

signals:

	/// �������� ������ ���������
	void somethingChange(QString message);

private:

	Ui::GameBoard *ui;
	QGraphicsScene *scene;	
	int getScore(string s);
	Weapons *weapons;
	QNetworkSession *networkSession;
	quint16 messageSize;
	QTcpServer *tcpServer;
	QTcpSocket *clientSocket;				
	bool isGame;
};


