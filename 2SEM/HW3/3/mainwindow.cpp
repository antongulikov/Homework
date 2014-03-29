#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	signalMapper->setMapping(ui->button0,"0");	
	signalMapper->setMapping(ui->button1,"1");
	signalMapper->setMapping(ui->button2,"2");
	signalMapper->setMapping(ui->button3,"3");
	signalMapper->setMapping(ui->button4,"4");
	signalMapper->setMapping(ui->button5,"5");
	signalMapper->setMapping(ui->button6,"6");
	signalMapper->setMapping(ui->button7,"7");
	signalMapper->setMapping(ui->button8,"8");
	signalMapper->setMapping(ui->button9,"9");
	
	connect(ui->button0, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button8, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->button9, SIGNAL(clicked()), signalMapper, SLOT(map()));
	
	signalMapper->setMapping(ui->divideButton,"/");
	signalMapper->setMapping(ui->minusButton,"-");
	signalMapper->setMapping(ui->multiplyButton,"*");
	signalMapper->setMapping(ui->plusButton,"+");
	
	connect(ui->divideButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->minusButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->multiplyButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(ui->plusButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
	
	connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeMonitor(QString)));
	connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(calcExpression()));
	connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearMonitor()));
		
}

void MainWindow :: changeMonitor(QString symbol){
	if (ui->resultLine->text() == "FAIL!!!")
		ui->resultLine->setText(symbol);
	else	
		ui->resultLine->setText(ui->resultLine->text() + symbol);
} 

void MainWindow :: clearMonitor(){
	ui->resultLine->setText("");
}

void MainWindow :: calcExpression(){
	int result = calc.calculate(ui->resultLine->text().toStdString().c_str());
	if (result == - (1 << 30))
		ui->resultLine->setText("FAIL!!!");
	else	
		ui->resultLine->setText(QString :: number(result));
}

MainWindow::~MainWindow()
{
	delete ui;
}
