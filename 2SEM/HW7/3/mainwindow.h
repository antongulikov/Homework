#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMenu>
#include <QMessageBox>
#include <QAction>
#include "getsizedialog.h"
#include "tictactoe.h"

namespace Ui {
	class MainWindow;
}
/// осоновное окно приложения
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	/// изменить размер поля
	void changeSize(int newSize);
	/// изменить длину цепи
	void changeLength(int newValue);

private slots:
	/// слот для изменения размера поля
	void changeBoardSize();
	/// слот, показывающий суть игры
	void showAbout();
	/// краткие правила
	void showRules();
	/// перезапуск игры
	void restart();
	/// слот для изменения длины цепи
	void changeWinLength();
	
private:
	Ui::MainWindow *ui;
	QMessageBox msb;	
	TicTacToe *game;
};

#endif // MAINWINDOW_H
