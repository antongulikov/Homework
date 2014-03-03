#include <arraystack.h>
#include <cstdio>

int main()
{
    Stack<int> *aStack = new ArrayStack<int>();
    aStack->push(2);
    aStack->push(3);
    printf("%d %d", aStack->pop(), aStack->pop());
    delete aStack;
    return 0;
}
