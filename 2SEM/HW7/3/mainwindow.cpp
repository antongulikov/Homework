#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),
game(new TicTacToe(3, this))
{	
	ui->setupUi(this);
	this->setWindowTitle("BelarussianTicTacToe");	
	setCentralWidget(game);
	QMenu *myMenu = menuBar()->addMenu("Options");
	myMenu->addAction("Change Size", this, SLOT(changeBoardSize()));
	myMenu->addAction("Change winLength", this, SLOT(changeWinLength()));
	myMenu->addAction("Restart", this, SLOT(restart()));
	QMenu *help = menuBar()->addMenu("Help");
	help->addAction("About", this, SLOT(showAbout()));
	help->addAction("Rules", this, SLOT(showRules()));		
	connect(this, SIGNAL(changeSize(int)), game, SLOT(changeSize(int)));
	connect(this, SIGNAL(changeLength(int)), game, SLOT(changeWinLength(int)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::changeBoardSize()
{
	GetSizeDialog *getNewSize = new GetSizeDialog(this);
	int newSize = getNewSize->exec();
	delete getNewSize;
	emit changeSize(newSize);
}

void MainWindow::changeWinLength()
{
	GetSizeDialog *getNewSize = new GetSizeDialog(this);
	int newSize = getNewSize->exec();
	delete getNewSize;
	emit changeLength(newSize);
}


void MainWindow::showAbout()
{
	msb.setText("Обычные крестики-нолики с белорусским оттенком!");
	msb.show();
}

void MainWindow::showRules()
{
	msb.setText("Замостите N подряд клеток по вертикали, горизонтали или диагонали!");	
	msb.show();
}

void MainWindow::restart()
{	
	game->restart();
}
