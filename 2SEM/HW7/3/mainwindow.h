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
/// ��������� ���� ����������
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	/// �������� ������ ����
	void changeSize(int newSize);
	/// �������� ����� ����
	void changeLength(int newValue);

private slots:
	/// ���� ��� ��������� ������� ����
	void changeBoardSize();
	/// ����, ������������ ���� ����
	void showAbout();
	/// ������� �������
	void showRules();
	/// ���������� ����
	void restart();
	/// ���� ��� ��������� ����� ����
	void changeWinLength();
	
private:
	Ui::MainWindow *ui;
	QMessageBox msb;	
	TicTacToe *game;
};

#endif // MAINWINDOW_H
