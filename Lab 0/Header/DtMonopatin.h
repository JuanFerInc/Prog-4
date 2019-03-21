#ifndef DTMONOPATIN_H
#define DTMONOPATIN_H

#include "DtVehiculo.h"

class DtMonopatin: public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        //Constructor
		DtMonopatin();
        DtMonopatin(int,float,float,bool );
		DtMonopatin(const DtMonopatin&);
        //Getters
        bool gettieneLuces() const;
		float getprecioBase() const;
		virtual ~DtMonopatin() = default;
};
#endif 