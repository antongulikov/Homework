#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QDebug>

TicTacToe::TicTacToe(QWidget *parent) :
QWidget(parent),
ui(new Ui::TicTacToe),
numberOfSteps(0),
N(3),
winLength(3),
buttons(QVector <QPushButton*>(3*3))
{
	field = new states*[N];
	for (int i = 0; i < N; i++){
		field[i] = new states[N];		
	}	
	ui->setupUi(this);
	drowField();	
}

TicTacToe::TicTacToe(int size, QWidget *parent) :
N(size),
winLength(3),
QWidget(parent),
numberOfSteps(0),
ui(new Ui::TicTacToe),
buttons(QVector <QPushButton*>(size * size))
{
	field = new states*[N];
	for (int i = 0; i < N; i++){
		field[i] = new states[N];		
	}
	ui->setupUi(this);	
	drowField();	
}

TicTacToe::~TicTacToe()
{
	deleteArrays();
	delete ui;
}

void TicTacToe::restart()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			field[i][j] = nothing;
	for (int i = 0; i < N * N; i++){
		buttons[i]->setStyleSheet("color : black; background-color: grey;");
	}		
	numberOfSteps = 0;			
}

void TicTacToe::nextStep(int position)
{
	int x = position / N;
	int y = position % N;
	if (field[x][y] != nothing){
		showMessage("Это поле уже занятно одной из сторон!\nВыбирете другое поле!");	
		return;
	}
	numberOfSteps++;
	switch (numberOfSteps & 1){
		case 1:
		{
			field[x][y] = green;
			buttons[position]->setStyleSheet("color : black; background-color: green;");
			if (winPosition())
			{
				showMessage("Зелёные победили!\n");
				restart();
				return;
			}
			break;
		}
		case 0:
		{
			field[x][y] = red;
			buttons[position]->setStyleSheet("color : black; background-color: red;");
			if (winPosition())
			{
				showMessage("Красные победили!");			
				restart();
				return;
			}
			break;
		}
	}
	if (numberOfSteps == N * N){
		showMessage("Будет новая битва!");
		restart();
		}
}

void TicTacToe::changeSize(int newSize)
{
	delete buttonMapper;
	deleteArrays();
	delete grid;
	N = newSize;
	field = new states*[N];
	for (int i = 0; i < N; i++){
		field[i] = new states[N];		
	}
	buttons.resize(N * N);	
	drowField();	
}

void TicTacToe::changeWinLength(int newValue)
{
	winLength = newValue;
	restart();
}

void TicTacToe::showMessage(const QString &message)
{
	msb.setText(message);
	msb.show();
}

bool TicTacToe::winPosition()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (field[i][j] != nothing)
				if (winHorizont(i, j) || winVertical(i, j) || winDiagonal(i, j))
					return true;
	return false;	
}

bool TicTacToe::winHorizont(int x, int y)
{
	int count = 0;
	if (y + winLength - 1 >= N)
		return false;
	for (int i = 0; i < winLength; i++)
		count += field[x][y] == field[x][y + i];
	return (count == winLength);	
}

bool TicTacToe::winVertical(int x, int y)
{
	int count = 0;
	if (x + winLength - 1 >= N)
		return false;
	for (int i = 0; i < N; i++)
		count += field[x][y] == field[x + i][y];
	return (count == winLength);	
}

bool TicTacToe::winDiagonal(int x, int y)
{
	int count =  0;
	for (int i = 0; i < winLength && x + i < N && y + i < N; i++){
		count += field[x][y] == field[x + i][y + i];
	}
	if (count == winLength)
		return true;
	count = 0;
	for (int i = 0; i < winLength && x + i < N && y - i >= 0; i++){
		count += field[x][y] == field[x + i][y - i];
	}	
	return (count == winLength);
}

void TicTacToe::deleteArrays()
{
	for (int i = 0; i < N; i++)
		delete[] field[i];
	delete[] field;
	for (int i = 0; i < buttons.size(); i++)
		delete buttons[i];
	buttons.clear();		
}


void TicTacToe::drowField()
{
	buttonMapper = new QSignalMapper(this);
	grid = new QGridLayout(this);
	for (int i = 0; i < N * N; i++){
		field[i / N][i % N] = nothing;
		QPushButton *newButton = new QPushButton(this);
		buttons[i] = newButton;
		newButton->setMinimumSize(50, 50);
		newButton->setEnabled(true);
		newButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
		connect(newButton, SIGNAL(clicked()), buttonMapper, SLOT(map()));
		buttonMapper->setMapping(newButton, i);
		grid->addWidget(newButton, i / N, i % N);					
	}
	restart();
	connect(buttonMapper, SIGNAL(mapped(int)), this, SLOT(nextStep(int)));
	setLayout(grid);
}
