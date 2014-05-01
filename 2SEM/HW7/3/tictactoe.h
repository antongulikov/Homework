#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <vector>
#include <QObject>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include <QSizePolicy>
#include <QMessageBox>
#include <QVector>

using namespace std;

namespace Ui {
	class TicTacToe;
}
/// класс для игры в TicTacToe
class TicTacToe : public QWidget
{
	Q_OBJECT
	
public:
	explicit TicTacToe(QWidget *parent = 0);
	explicit TicTacToe(int size, QWidget *parent = 0);
	~TicTacToe();
	void restart();
	
private slots:
	/// делает ход игрока
	void nextStep(int position);
	/// изменят размер поля
	void changeSize(int newSize);
	/// изменяет длину цепочки
	void changeWinLength(int newValue);
	
private:
	int N;
	Ui::TicTacToe *ui;
	enum states{nothing, red, green};
	states **field;	
	QVector <QPushButton*> buttons;
	QSignalMapper *buttonMapper;
	QMessageBox msb;
	QGridLayout *grid;
	int numberOfSteps;
	int winLength;
	/// рисует игровое поле
	void drowField();
	void showMessage(const QString &message);
	/// определяет выигрышность позиции
	bool winPosition();
	bool winHorizont(int x, int y);
	bool winVertical(int x, int y);
	bool winDiagonal(int x, int y);
	void deleteArrays();	
};

#endif // TICTACTOE_H
