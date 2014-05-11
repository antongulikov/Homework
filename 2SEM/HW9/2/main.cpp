/*#include "HashTableManager.h"
using namespace std;

int main()
{
    HashTableManager *HTmanager = new HashTableManager;
    HTmanager->dialog();
    delete HTmanager;
    cout << "Program has finished." << endl;
}*/

#include "ListTest.h"
#include "HashTableTest.h"
int main()
{
    ListTest ltest;
    QTest::qExec(&ltest);
    HashTableTest htest;
    QTest::qExec(&htest);
    return 0;
}
