#pragma once
#include <QObject>

/// class which allow to calculate expressions

class Calculator : public QObject
{
	Q_OBJECT
	
public:
	/// function that calculate
	int calculate(int first, QString sign, int second);	
};
