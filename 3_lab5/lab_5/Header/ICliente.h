#ifndef ICLIENTE_H
#define ICLIENTE_H

#include <iostream>

using namespace std;

class IVenta{
    public:
        virtual void verActualizacion(string tel, string clave) =0;
        

};

#endif


