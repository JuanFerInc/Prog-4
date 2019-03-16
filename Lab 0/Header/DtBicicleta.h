#ifndef DTBICICLETA_H
#define DTBICICLETA_H

#include "DtVehiculo.h"
#include "TipoBici.h"

class DtBicicleta: public DtVehiculo{
    private:
        TipoBici tipo;
        int cantCambios;
    public:
        //Constructor
        DtBicicleta(TipoBici,int);
        //Getters
        TipoBici get_TipoBici();
        int get_cantCambios();
};

#endif