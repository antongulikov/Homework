#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bash.h"
#include <QMap>
#include <QVector>

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
	void showFirstElement(QVector<QWebElementCollection> tmpMessage);
	/// not interested news
	void nothing();
	/// good news
	void plus();
	/// bad news;
	void minus();
	
private:
	Ui::MainWindow *ui;
	int numberOfElements;
	int currentPosition;
	QWebElementCollection myList;
	QWebElementCollection ratings;
	Bash *bashElement;
	QMap<QString, bool> used;
	QMap<QString, int> rating;
	void changeRating(int value);
	void setRead();
	void setText(int position);
};

#endif // MAINWINDOW_H
