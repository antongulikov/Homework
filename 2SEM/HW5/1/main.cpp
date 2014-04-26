#include <iostream>
#include "tree.h"
#include "treetest.h"

using namespace std;

int main()
{
	TreeTest treeTest;
	QTest :: qExec(&treeTest);
	
	Tree tr("(+ (* (+ 1 1) 2) (- 5 4) )");
	cout << tr.count();
	cout << endl;
	tr.print();
	
	return 0;
}

