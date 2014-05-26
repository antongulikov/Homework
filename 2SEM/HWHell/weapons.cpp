#include "weapons.h"
#include <QDebug>

Weapons::Weapons(int width, int height) : width(width), height(height), player(0), isShooting(false), timeCount(0), finished(false)
{
	angle[0] = 0;
	angle[1] = 180;
	speed[0] = 10;
	speed[1] = 10;
	players[0].setRect(7, height + 3, 40, 40);
	players[1].setRect(width - 26, height + 3, 40, 40);
	shootTimer = new QTimer(this);
	setFlag(QGraphicsItem::ItemIsFocusable);
	connect(shootTimer, SIGNAL(timeout()), this, SLOT(moveShoot()));	
	connect(this, SIGNAL(endGame(bool)), this, SLOT(restart(bool)));
}

Weapons::~Weapons()
{
	delete shootTimer;
}


void Weapons::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setPen(Qt::darkCyan);
	painter->setBrush(Qt::darkCyan);
	painter->drawRect(0, height + 43, width + 100, 100);
	paintRect(painter, 0);		
	paintRect(painter, 1);
	
	if (isShooting)
		paintShoot(painter, player);
}

void Weapons::keyPressEvent(QKeyEvent *event)
{	
	if (isShooting)
		return;
		
	int add = (player == 0) ? 1 : -1;
	switch(event->key())
	{		
		case Qt::Key_Up :
		{	
			angle[player] -= add;
			break;
		}
		
		case Qt::Key_Down :
		{			
			angle[player] += add;
			break;
		}
		
		case Qt::Key_Space:
		{	
			player ^= 1;
			break;							
		}
		
		case Qt::Key_S:
		{
			makeShoot(player);			
			break;
		}
		
		case Qt::Key_Left:
		{
			changeSpeed(-1);
			break;
		}
		
		case Qt::Key_Right:
		{
			changeSpeed(1);
			break;
		}
	}
	
	update();
}


QRectF Weapons::boundingRect() const
{
		return QRectF(0, 0, width + 50, height + 50);
}
		
QRectF Weapons::gun() const
{
	return QRectF(0, 0, 30, 5);		
}

void Weapons::moveShoot()
{
	timeCount++;
	QRegion region = shotRect();
	//qDebug() << timeCount << "\n";
	QRect rect = shotRect();
	if (rect.intersects(players[player ^ 1]))
	{
		shootTimer->stop();
		isShooting = false;
		emit endGame(true);
		emit winner(player);
		return;
	} else if (rect.x() > width + 50 || rect.y() > height + 50 || rect.x() < 0 || rect.y() < 0)
	{
		isShooting = false;
		shootTimer->stop();		
		player ^= 1;
	} else
		region = region.united(rect);
	update();		
}

void Weapons::restart(bool fl)
{
	if (!fl)
		return;
	isShooting = false;
	finished = true;
	angle[0] = 0;
	angle[1] = 180;
	speed[0] = 10;
	speed[1] = 10;		
	update();	
	finished = false;
}

void Weapons::makeShoot(int player)
{
	if (isShooting)
		return;
		
	isShooting = true;		
	timeCount = 0;
	shootTimer->start(5);	
}

void Weapons::paintShoot(QPainter *painter, int pos)
{
	if (pos == 0)	
		painter->setPen(Qt::green), painter->setBrush(Qt::green);
	if (pos == 1)
		painter->setPen(Qt::green), painter->setBrush(Qt::green);		
	QRect object = shotRect();
	painter->drawEllipse(object.x(), object.y(), object.width(), object.height());
}

void Weapons::paintRect(QPainter *painter, int pos)
{	
	if (pos == 0)	
		painter->setPen(Qt::red), painter->setBrush(Qt::red);
	if (pos == 1)
		painter->setPen(Qt::blue), painter->setBrush(Qt::blue);			
	painter->drawEllipse(players[pos].x(), players[pos].y(), players[0].width(), players[pos].height());		
	painter->translate(players[pos].x() + players[pos].width() / 2, players[pos].y() + players[pos].height() / 2);
	painter->rotate(angle[pos]);
	painter->drawRect(gun());
	painter->rotate(-angle[pos]);
	painter->translate(-players[pos].x() - players[pos].width() / 2, -players[pos].y() - players[pos].height() / 2);		
}

void Weapons::paintText(QPainter *painter, QString message)
{
	
}

QRect Weapons::shotRect() const
{
	double radians = -angle[player] * acos(-1.0) / 180.;		
	double gravity = 9.81;
	double x0 = players[player].x() + players[player].width() / 2;
	double y0 = players[player].y() + players[player].height() / 2;		
	x0 = x0 + (gun().width() + 5) * cos(radians);
	y0 = y0 - (gun().width() + 5) * sin(radians);	
	double speedX = speed[player] * cos(radians);
	double speedY = speed[player] * sin(radians);
	double time = timeCount / 20.;
	x0 = x0 + speedX * time;
	y0 = y0 - (speedY * time - 0.5 * gravity * time * time);
	QRect result(0, 0, 5, 5);
	result.moveCenter(QPoint(qRound(x0), qRound(y0)));
	return result;					
}

void Weapons::changeSpeed(int value)
{
	int newSpeed = value + speed[player];
	if (newSpeed >= 5 && newSpeed <= 120)
	{
		speed[player] = newSpeed;
	}
}
