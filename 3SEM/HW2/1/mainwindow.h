#pragma once
#include "network.h"
#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void drawUI();
    void makeTurn();
    void initUI();

private:
    void buildNetwork();
    Ui::MainWindow *ui;
    Network *network;
    QVector <QLabel *> labels;
    int compSize;
    int turnNumbers;
    QLabel *turnLabel;
};

