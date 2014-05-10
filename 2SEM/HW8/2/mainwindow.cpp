#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), bashElement(nullptr), ui(new Ui::MainWindow), numberOfElements(1)
{
	used.clear();
	rating.clear();
	ui->setupUi(this);	
	ui->loadButton->setEnabled(true);
	ui->nextButton->setEnabled(true);	
	connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadInformation()));
	connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(showNext()));		
	connect(ui->badButton, SIGNAL(clicked()), this, SLOT(nothing()));
	connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(plus()));
	connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(minus()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::loadInformation()
{
	ui->loadButton->setEnabled(false);
	ui->nextButton->setEnabled(false);	
	ui->textView->setText("Please, wait!");
	if (bashElement)
		delete bashElement;
	bashElement = new Bash(this);
	connect(bashElement, SIGNAL(readyToWork(QVector<QWebElementCollection>)), this, SLOT(showFirstElement(QVector<QWebElementCollection>)));	
}

void MainWindow::showNext()
{
	currentPosition = (currentPosition + 1)	% numberOfElements;
	setText(currentPosition);
}

void MainWindow::showFirstElement(QVector<QWebElementCollection> tmpMessage)
{
	currentPosition = 0;
	numberOfElements = tmpMessage.at(0).toList().length();
	myList = tmpMessage.at(0);
	ratings = tmpMessage.at(1);
	setText(0);
	ui->loadButton->setEnabled(true);
	ui->nextButton->setEnabled(true);		
}

void MainWindow::nothing()
{
	setRead();
	changeRating(0);
}

void MainWindow::plus()
{
	setRead();
	changeRating(1);	
}

void MainWindow::minus()
{
	setRead();
	changeRating(-1);	
}

void MainWindow::changeRating(int value)
{
	int currentRating = ui->currentRatingLine->text().toInt() + value;
	ui->currentRatingLine->setText(QString::number(currentRating));
	rating[myList.at(currentPosition).toPlainText()] = currentRating;	
}

void MainWindow::setRead()
{
	used[myList.at(currentPosition).toPlainText()] = true;
	ui->plusButton->setEnabled(false);
	ui->minusButton->setEnabled(false);
	ui->badButton->setEnabled(false);
}

void MainWindow::setText(int position)
{
	QString bashMessage = myList.at(position).toPlainText();
	ui->textView->setText(bashMessage);
	switch (used[bashMessage])
	{
		case true:
		{
			ui->plusButton->setEnabled(false);
			ui->minusButton->setEnabled(false);
			ui->badButton->setEnabled(false);
			ui->currentRatingLine->setText(QString:: number(rating[bashMessage]));
			break;
		}
		case false:
		{
			ui->plusButton->setEnabled(true);
			ui->minusButton->setEnabled(true);
			ui->badButton->setEnabled(true);
			ui->currentRatingLine->setText(ratings.at(position).toPlainText());
			break;
		}	
	}		
}
