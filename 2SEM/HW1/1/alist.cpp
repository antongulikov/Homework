#include "alist.h"
#include <iostream>

using namespace std;

ArrayList :: ArrayList() : actualSize(0){
}

ArrayList :: ~ArrayList(){
}


void ArrayList :: push(int value){
    a[actualSize++] = value;
}

void ArrayList :: pop(int value){
    for (int i = 0; i < actualSize; i++)
        if (a[i] == value){
            for (int j = i + 1; j < actualSize; j++){
                a[j - 1] = a[j];
            }
            actualSize--;
            return;
        }
}

bool ArrayList :: find(int value){
    for (int i = 0; i < actualSize; i++)
        if (a[i] == value)
            return true;
    return false;            
}

void ArrayList :: print(){
    for (int i = 0; i < actualSize; i++)
        cout << a[i] << " ";
    cout << endl;    
}

int ArrayList :: size(){
    return actualSize;
}
