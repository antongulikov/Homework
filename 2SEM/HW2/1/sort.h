#pragma once

class Sort{	
	public:
		virtual ~Sort();
		/// Method which sorts an array
		virtual void sort(int *args, int length) = 0;	
	protected :
		/// Method which swaps two elements
		void swap(int &firstElement,int &secondElement);	
};
