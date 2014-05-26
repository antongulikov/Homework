#pragma once
#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <weapons.h>

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
	void startGame();
	
private:
	Ui::GameBoard *ui;
	QGraphicsScene *scene;	
	
};


