#ifndef B_H
#define B_H
#include "C.h"
class A;

class B{
    private: 
        int b;
        A* rela;
        C* relc;
    public:
        B(int arg);
        void imprimirb();
};

#include "A.h" 

#endif
