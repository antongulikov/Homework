#pragma once
#include <QMainWindow>
#include "calculator.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;
	Calculator calc;

private slots:
	void recalc();
	
};

