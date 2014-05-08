#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), bashElement(nullptr), ui(new Ui::MainWindow), numberOfElements(1)
{
	ui->setupUi(this);	
	ui->loadButton->setEnabled(true);
	ui->nextButton->setEnabled(true);	
	connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadInformation()));
	connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(showNext()));		
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
	connect(bashElement, SIGNAL(readyToWork(QWebElementCollection)), this, SLOT(showFirstElement(QWebElementCollection)));	
}

void MainWindow::showNext()
{
	currentPosition = (currentPosition + 1)	% numberOfElements;
	ui->textView->setText(myList.at(currentPosition).toPlainText());
}

void MainWindow::showFirstElement(QWebElementCollection tmpList)
{
	currentPosition = 0;
	numberOfElements = tmpList.toList().length();
	myList = tmpList;
	ui->textView->setText(myList.at(0).toPlainText());	
	ui->loadButton->setEnabled(true);
	ui->nextButton->setEnabled(true);		
}

