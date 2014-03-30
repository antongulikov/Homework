#include <iostream>

using namespace std;

class ShowA{
	public:
		ShowA(){
			cout << "Create A\n";
		}
		~ShowA(){
			cout << "Destroy A\n";
		}
};

class ShowB{
	public:
		ShowB(){
			cout << "Create B\n";
		}
		~ShowB(){
			cout << "Destroy B\n";
		}
};

class ShowC{
	public:
		ShowC(){
			cout << "Create C\n";
		}
		~ShowC(){
			cout << "Destroy C\n";
		}
};

class Exec{
	public:
		Exec(){
			cout << "Create Exec\n";
		}
		~Exec(){
			cout << "Destroy exec\n";	
		}
};

int main(){
	try{
		ShowA a;
		ShowB b;
		ShowC c;
		throw Exec();
	}
	catch(...){
		cout << "Catching...\n";
	}
	return 0;
}


