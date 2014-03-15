#include "calculator.h"

int Calculator::calculate(int first, QString sign, int second){
	switch (sign.at(0).toLatin1())
	{
		case ('+'):
			return first + second;			
		case ('-'):
			return first - second;			
		case ('*'):
			return first * second;			
		case ('/'):
			if (second == 0)
				return (first < 0 ? 1 : -1) * (1 << 30);
			return first / second; 		
	}
}
