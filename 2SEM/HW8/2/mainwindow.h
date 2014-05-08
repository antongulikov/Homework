#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bash.h"

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
	/// load information from bash.im
	void loadInformation();	
	/// show next message from the site
	void showNext();
	/// show the first message from the site
	void showFirstElement(QWebElementCollection tmpList);
	
private:
	Ui::MainWindow *ui;
	int numberOfElements;
	int currentPosition;
	QWebElementCollection myList;
	Bash *bashElement;
};

#endif // MAINWINDOW_H
