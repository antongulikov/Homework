#ifndef PAIR_H
#define PAIR_H

/// class for pair

class Pair
{
public:
	Pair();
	~Pair();
	Pair(int valueA, int valueB);	
	void multiply(int value);
	Pair operator +(Pair const &second);
	int getA();
	int getB();	
			
protected:
	int a;
	int b;
};

#endif // PAIR_H
