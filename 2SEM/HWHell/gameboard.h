#pragma once
#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include <weapons.h>
#include <string>
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
	void startGame();
	void changeScore(int player);
	
private:
	Ui::GameBoard *ui;
	QGraphicsScene *scene;	
	int getScore(string s);
	
};


