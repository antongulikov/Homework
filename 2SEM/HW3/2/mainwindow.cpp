#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->firstArgument, SIGNAL(valueChanged(int)), this, SLOT(recalc()));
	connect(ui->secondArgument, SIGNAL(valueChanged(int)), this, SLOT(recalc()));
	connect(ui->sign, SIGNAL(currentIndexChanged(int)), this, SLOT(recalc()));	

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::recalc(){
	int firstElement = ui->firstArgument->value();
	int secondElement = ui->secondArgument->value();
	QString sign = ui->sign->currentText();
	int tmpValue = calc.calculate(firstElement, sign, secondElement);
	QString result = QString :: number(tmpValue);
	emit ui->result->setText(result);
}
