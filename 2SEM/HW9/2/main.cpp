#include "HashTableManager.h"
#include "ListTest.h"
#include "HashTableTest.h"
using namespace std;

int main()
{
	ListTest ltest;  
    QTest::qExec(&ltest);
    HashTableTest htest;
    QTest::qExec(&htest);    
}
