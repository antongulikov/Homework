#pragma once

class Sort{	
	public:
		Sort();
		virtual ~Sort();
		virtual void sort(int *args, int length) = 0;	
	protected :
		void swap(int &firstElement,int &secondElement);	
};
