#pragma once
#include <QGraphicsItem>
#include <QMainWindow>
#include <QRegion>
#include <QMessageBox>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QWidget>
#include <QKeyEvent>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;


class Weapons :  public QObject, public QGraphicsItem 
{ Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
  
public:
	Weapons(int widht, int height);	
	~Weapons();
	
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void keyPressEvent(QKeyEvent *event);
	QRectF boundingRect() const;
	QRectF gun() const;

	
private slots:
	void moveShoot();
	void restart(bool fl);
signals:
	void endGame(bool fl);	
	void winner(int player);
	
private:
	int width;
	int height;
	int player;	
	int angle[2];
	bool isShooting;
	void makeShoot(int player);
	void paintShoot(QPainter *painter, int pos);
	void paintRect(QPainter *painter, int pos);
	void paintText(QPainter *painter, QString message);	
	int timeCount;
	int speed[2];
	QTimer *shootTimer;
	QRect players[2];
	QRect shotRect() const;
	void changeSpeed(int value);
	bool finished;
};


