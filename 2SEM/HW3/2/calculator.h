#pragma once
#include <QObject>

class Calculator : public QObject
{
	Q_OBJECT
	
public:
	int calculate(int first, QString sign, int second);	
};
