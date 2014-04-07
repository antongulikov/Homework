#pragma once
#include <map>
using namespace std;

/// Class for multiset
class Bag
{
public:

	Bag();	
	~Bag();
	void insert(int vaue);
	void erase(int value);
	int getSize();
	bool find(int value);
	
private:
	/// Map for simulate multiset
	map<int, int> helperMap;
	int size;
};


