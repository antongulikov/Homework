#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
ui(new Ui::GameBoard)
{
	ui->setupUi(this);	
	setWindowTitle(tr("Зачётная пушка"));
	connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startGame()));		
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
	scene->setBackgroundBrush(Qt :: black);
	Weapons *weapons = new Weapons(ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);
	weapons->setFocus();
	scene->addItem(weapons);	
	ui->graphicsView->setScene(scene);			
}
