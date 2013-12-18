#include "double.h"
#include <algorithm>
#include <cstdio>
#include <stdlib.h>

using namespace std;


namespace scorpion{

	enum state{
		sstart,
		sabs,
		snum,
		spoint,
		sreal,
		sexp,
		sexpabs,
		sdouble
	};


	bool isDigit(char ch){
		return ('0' <= ch && ch <= '9');
	}

	int nextPosition(int currentPosition, char currentSymbol){

		switch (currentPosition){

			case sstart : {
				if (currentSymbol == '+' || currentSymbol == '-')
					return sabs;
				if (isDigit(currentSymbol))
					return snum;
				return -1;

			}

			case sabs : {
				if (isDigit(currentSymbol))
					return snum;
				return -1;
			}
	
			case snum : {
				if (isDigit(currentSymbol))
					return snum;
				if (currentSymbol == 'E')
					return sexp;
					if (currentSymbol == '.')
					return spoint;
				return -1;
			}
	
			case spoint : {
				if (isDigit(currentSymbol))
					return sreal;
				return -1;
			}
								
			case sreal : {
				if (isDigit(currentSymbol))
					return sreal;
				if (currentSymbol == 'E')
					return sexp;
				return -1;						
			}

			case sexp : {
				if (currentSymbol == '+' || currentSymbol == '-')
					return sexpabs;
				if (isDigit(currentSymbol))
					return sdouble;
				return -1;
			}			
			case sexpabs : {
				if (isDigit(currentSymbol))
					return sdouble;
				return -1;
			}
	
			case sdouble : {
				if (isDigit(currentSymbol))
					return sdouble;
				return -1;			
			}
		}	 
	}


	bool isDouble(char *parseString, int &start, int &finish){

		int currentPosition = 0;

		bool *fail = new bool[8];
		
		for (int i = 0; i < 8; i++) 
			fail[i] = i % 2;

		swap(fail[7], fail[6]);

		int previousPosition = 0;
		

		for (int i = start; i < finish; i++){

			previousPosition = currentPosition;

			if (parseString[i] == 'e')
				parseString[i] = 'E';

			currentPosition = nextPosition(currentPosition, parseString[i]);

			if (currentPosition == -1){
				start = i;
				break;
			}

		}

		if (currentPosition != -1)
			previousPosition = currentPosition;

		fail[0] = true;

		bool ans = fail[previousPosition];

		if (currentPosition != -1)
			start = finish;

		delete[] fail;
		return ! ans;
	}
}