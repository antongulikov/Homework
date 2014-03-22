#pragma once
#include <QString>
#include <QMainWindow>
#include <QSignalMapper>
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
	/// Method which clear resultLine
	void clearMonitor();
	/// Method which adds a symbol to monitor
	void changeMonitor(QString symbol);
	/// Method which shows result
	void calcExpression();		
	
};
