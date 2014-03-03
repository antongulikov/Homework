#pragma once
#include "list.h"

class ArrayList : public List
{

    public:
        ArrayList();
        ~ArrayList();
        void push(int value);
        void pop(int value);
        bool find(int value);
        void print();
        int size();
    
    private :        
        int a[141195];
        int actualSize;
    
};

