#ifndef A_H
#define A_H

#include "B.h"
#include "C.h"

class A {
    private:
        int a;
        B* relb;
        C* relc;
    public:
        A(int arg);
        void imprimira();
}; 

#endif
