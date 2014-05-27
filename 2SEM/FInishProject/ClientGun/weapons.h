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
{ 
	Q_OBJECT
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

	/// произведём выстрел
	void moveShoot();
	/// начать ещё одну игру
	void restart(bool fl);
	/// оппонент сделал ход
	void opponentEvent(QString message);

signals:

	/// закончить игру
	void endGame(bool fl);	
	/// пошлём победителя
	void winner(int player);
	/// сигнал от нас, что мы что-то сделали
	void playerEvent(QString message);
	
private:
	/// ширина игрового поля
	int width;
	/// высота игрового поля
	int height;
	/// кто сейчас ходит
	int player;	
	/// угол поворота дула относительно центра пушки
	int angle[2];
	/// летит ли зелёная штучка, называемая снарядом
	bool isShooting;
	/// совершить выстрел
	void makeShoot(int player);
	/// нарисовать выстрел
	void paintShoot(QPainter *painter, int pos);
	/// нарисвовать пушку
	void paintRect(QPainter *painter, int pos);
	/// отсчёт времени
    int timeCount;
    /// скорость снаряда
	int speed[2];	
	QTimer *shootTimer;
	QRect players[2];
	QRect shotRect() const;
	void changeSpeed(int value);
	bool finished;
};


