#include <iostream>
#include "sharedpointertest.h"

using namespace std;

int main()
{

/*	SharedPointer<int> *pt1 = new SharedPointer<int>(new int(42));
	cout << pt1->getCount() << endl;
	cout << *pt1->getPointer() << endl;
	SharedPointer<int> pt2(new int(24));
	*pt1 = pt2;
	cout << pt1->getCount() << endl;
	cout << *pt1->getPointer() << endl;
	cout << pt2.getCount() << endl;
	cout << *(pt2.getPointer()) << endl;		
	delete pt1;
	cout << pt2.getCount() << endl;
	cout << *(pt2.getPointer()) << endl;		
*/
	SharedPointerTest spTest;
	QTest :: qExec(&spTest);
		
	return 0;
}

