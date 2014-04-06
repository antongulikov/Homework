#pragma once
#include <set>
using namespace std;

/// template class for Set
template <typename T>
class MySet
{
public:

	MySet(){
		helperSet.clear();
	}
	
	void insert(T value){
		helperSet.insert(value);
	}
	
	void erase(T value){
		helperSet.erase(value);
	}
	
	bool find(T value){
		return (helperSet.find(value) != helperSet.end());
	}
	
	MySet<T> intersectSet(MySet<T> secondSet){
		MySet<T> res;
		for (const T &it : helperSet){
			if (secondSet.find(it))
				res.insert(it);		
		}
		return res;			
	}
	
	MySet<T> unionSet(MySet<T> secondSet){
		MySet<T> res = secondSet;
		for (const T &it : helperSet)
			res.insert(it);
		return res;
	}
	
	int sizeSet(){
		return helperSet.size();
	}
	
private :
	set <T> helperSet;
};

