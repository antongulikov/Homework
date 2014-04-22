#pragma once

/// Basic class for list
class List{

	public :
		List();
		virtual ~List() = 0;
		virtual void push(int value) = 0;
		virtual void pop(int value) = 0;
		virtual bool find(int value) = 0;
		virtual void print() = 0;
		virtual int getSize() = 0;                     
};
