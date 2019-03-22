#ifndef DTMONOPATIN_H
#define DTMONOPATIN_H


#include "DtVehiculo.h"

class DtMonopatin: public DtVehiculo{
    private:
        bool tieneLuces;
    public:
        //Constructor
		DtMonopatin();
		//DtMonopatin(nroSerie,porcentaje,precioBase,tieneluces)
        DtMonopatin(int,float,float,bool );
		DtMonopatin(const DtMonopatin&);
        //Getters
        bool gettieneLuces() const;
		float getprecioBase() const;
		void print(std::ostream&);

		
		
		
		virtual ~DtMonopatin() = default;
};

#endif 