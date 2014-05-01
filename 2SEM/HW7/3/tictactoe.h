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
/// ����� ��� ���� � TicTacToe
class TicTacToe : public QWidget
{
	Q_OBJECT
	
public:
	explicit TicTacToe(QWidget *parent = 0);
	explicit TicTacToe(int size, QWidget *parent = 0);
	~TicTacToe();
	void restart();
	
private slots:
	/// ������ ��� ������
	void nextStep(int position);
	/// ������� ������ ����
	void changeSize(int newSize);
	/// �������� ����� �������
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
	/// ������ ������� ����
	void drowField();
	void showMessage(const QString &message);
	/// ���������� ������������ �������
	bool winPosition();
	bool winHorizont(int x, int y);
	bool winVertical(int x, int y);
	bool winDiagonal(int x, int y);
	void deleteArrays();	
};

#endif // TICTACTOE_H
