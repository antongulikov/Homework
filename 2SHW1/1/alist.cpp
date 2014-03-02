#include "alist.h"
#include <iostream>

using namespace std;

AList :: AList() : actualSize(0){
}

AList :: ~AList(){
}


void AList :: push(int value){
    a[actualSize++] = value;
}

void AList :: pop(int value){
    for (int i = 0; i < actualSize; i++)
        if (a[i] == value){
            for (int j = i + 1; j < actualSize; j++){
                a[j - 1] = a[j];
            }
            actualSize--;
            return;
        }
}

bool AList :: find(int value){
    for (int i = 0; i < actualSize; i++)
        if (a[i] == value)
            return true;
    return false;            
}

void AList :: print(){
    for (int i = 0; i < actualSize; i++)
        cout << a[i] << " ";
    cout << endl;    
}

int AList :: size(){
    return actualSize;
}
