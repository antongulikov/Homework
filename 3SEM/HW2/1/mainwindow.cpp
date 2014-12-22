#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    network(new Network),
    turnNumbers(0),
    turnLabel(nullptr)
{
    ui->setupUi(this);
    buildNetwork();
    drawUI();
    connect(ui->turn, SIGNAL(clicked()), this, SLOT(makeTurn()));

}

MainWindow::~MainWindow()
{
    for (int i = 0; i < labels.size(); ++i)
    {
        delete labels[i];
        labels[i] = nullptr;
    }
    labels.clear();
    delete ui;
    delete network;
}

void MainWindow::drawUI()
{
    turnLabel->setText(QString::number(turnNumbers) + "   turn");
    for (int i = 0; i < compSize; ++i)
    {
        if (network->isInfected(i))
            labels[i]->setText("Comp " + QString::number(i) + "  is infected");
        else
            labels[i]->setText("Comp " + QString::number(i) + "  is not infected");
    }
    turnNumbers++;
}

void MainWindow::makeTurn()
{
    network->makeTurn();
    drawUI();
}

void MainWindow::initUI()
{
    turnLabel = new QLabel();
    ui->verticalLayout->addWidget(turnLabel);
    for (int i = 0; i < compSize; ++i)
    {
        labels.push_back(new QLabel("Comp " + QString::number(i) + "  is not infected"));
        ui->verticalLayout->addWidget(labels[i]);
    }
}

void MainWindow::buildNetwork()
{
    freopen("in.txt","r", stdin);
    int n = 0;
    int m = 0;
    int t = 0;

    cin >> t;
    int pr[t];

    for (int i = 0; i < t; ++i)
        cin >> pr[i];

    string name[t];

    for (int i = 0; i < t; ++i)
        cin >> name[i];

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        x--;
        network->addNewComputer(new Computer(new Os(name[x], pr[x])));
    }

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x == 1)
            network->setInfect(i);
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        network->addEdge(x, y);
    }

    compSize = n;
    srand( time(0) );
    initUI();
}
