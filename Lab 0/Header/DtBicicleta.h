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

        //DtBicicleta(int nroSerie,float porcentaje,float precioBase, tipo, cantCambios)
        DtBicicleta(int,float,float,TipoBici,int);
        
        //Constructor
        DtBicicleta(TipoBici,int);
        //Getters
        TipoBici getTipoBici() const;
        int getcantCambios() const;

};

#endif