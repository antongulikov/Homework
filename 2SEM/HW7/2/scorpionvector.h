#pragma once
#include <vector>
#include <iostream>
using namespace std;
/// template class for Vector
template<int size>
class ScorpionVector{
public :

	ScorpionVector() : vec(vector <int>(size, 0)){
	}
	
	ScorpionVector(vector <int> const &vect) : vec(vect){
		vec.resize(size, 0);
	}
	
	ScorpionVector(ScorpionVector const &myScorpionVector) : vec(myScorpionVector.vec){
	}

	/// Is this null vector
	bool isNull(){
		for (int i = 0; i < size; i++)
			if (vec[i] != 0)
				return false;
		return true;
	}
	
	int getSize(){
		return vec.size();
	}		
	/// Scalar product this and second
	int scalarProduct(ScorpionVector const &second){
		int result = 0;
		for (int i = 0; i < size; i++)
			result += vec[i] * second.vec[i];
		return result;	
	}	
		
	ScorpionVector operator +(ScorpionVector const &second);
	ScorpionVector operator -(ScorpionVector const &second);
	bool operator ==(ScorpionVector const &second) const;		

private:
	vector<int> vec;
};

template <int size>
ScorpionVector<size> ScorpionVector<size> :: operator + (ScorpionVector const &second){
	vector <int> result(size,0);
	for (int i = 0; i < size; i++)
		result[i] = vec[i] + second.vec[i];
	return (ScorpionVector(result));
}

template <int size>
ScorpionVector<size> ScorpionVector<size> :: operator - (ScorpionVector const &second){
	vector <int> result(size,0);
	for (int i = 0; i < size; i++)
		result[i] = vec[i] - second.vec[i];
	return (ScorpionVector(result));
}

template <int size>
bool ScorpionVector<size> :: operator == (ScorpionVector const &second) const{
	if (vec.size() != second.vec.size())
		return false;
	for (int i = 0; i < size; i++)
		if (vec[i] != second.vec[i])
			return false;
	return true;
}

