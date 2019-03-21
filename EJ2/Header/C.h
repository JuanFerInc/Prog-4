#ifndef C_H
#define C_H

class A;
class B;

class C{
    private: 
        int c;
        A* rela;
        B* relb;
    public:
        C(int arg);
        void imprimirc();
};


#include "B.h" 
#include "C.h"

#endif
