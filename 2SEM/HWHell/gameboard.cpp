#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
ui(new Ui::GameBoard)
{
	ui->setupUi(this);	
	setWindowTitle(tr("Зачётные пушки"));
	connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startGame()));		
	ui->redLine->setReadOnly(true);
	ui->blueLine->setReadOnly(true);
	ui->redLine->setText("0");
	ui->blueLine->setText("0");	
}

GameBoard::~GameBoard()
{
	delete ui;
	delete scene;
}

void GameBoard::startGame()
{
	ui->startButton->setEnabled(false);
	scene = new QGraphicsScene(ui->graphicsView->x(), ui->graphicsView->y(), ui->graphicsView->width() - 10, ui->graphicsView->height() - 10, ui->graphicsView);	
	scene->setFocus();
	scene->setBackgroundBrush(Qt :: black);
	Weapons *weapons = new Weapons(ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);
	weapons->setFocus();
	connect(weapons, SIGNAL(winner(int)), this, SLOT(changeScore(int)));	
	scene->addItem(weapons);	
	ui->graphicsView->setScene(scene);			
}

void GameBoard::changeScore(int player)
{
	switch(player)
	{
		case 0 :
		{
			int currentScore = getScore(ui->redLine->text().toStdString()) + 1;
			ui->redLine->setText(QString :: number(currentScore));
			break;
		}
		case 1 :
		{
			int currentScore = getScore(ui->blueLine->text().toStdString()) + 1;
			ui->blueLine->setText(QString :: number(currentScore));
			break;
		}
	}
}

int GameBoard::getScore(string s)
{
	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		result = result * 10 + (int)(s[i] - '0');
	}
	return result;
}
