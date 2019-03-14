#ifndef DTMONOPATIN_H
#define DTMONOPATIN_H

#include "DtVehiculo.h"

class DtMonopatin: public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        //Constructor
        DtMonopatin(bool tieneLuces);
        //Getters
        bool get_tieneLuces();
        //Destructor
        ~DtMonopatin();
}

#endif
