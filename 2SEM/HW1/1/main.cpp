#include <alist.h>
#include <linlist.h>
#include <iostream>

using namespace std;

void testArrayList(){


    List *aList = new ArrayList();   
    
    aList->push(4);
    aList->push(3);
    aList->push(5);
    
    aList->print();
    
    cout << aList->find(3) << " " << aList->size() << endl;
    
    aList->pop(3);
    
    aList->print();
    
    cout << aList->size() << endl;
    
    delete aList;
    
}

void testLinList(){


    List *aList = new LinList();   
    
    aList->push(4);
    aList->push(3);
    aList->push(5);
    
    aList->print();
    
    cout << aList->find(3) << " " << aList->size() << endl;
    
    aList->pop(3);    
    
    aList->print();
    
    aList->pop(4);    
    
    aList->print();
    
    aList->pop(5);    
    
    cout << aList->size() << endl;
    
    delete aList;
    
}


int main(){
    testArrayList();
    testLinList();
   return 0;
}
