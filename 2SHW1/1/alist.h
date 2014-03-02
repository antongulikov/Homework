#pragma once
#include "list.h"

class AList : public List
{

    public:
        AList();
        ~AList();
        void push(int value);
        void pop(int value);
        bool find(int value);
        void print();
        int size();
    
    private :        
        int a[141195];
        int actualSize;
    
};

