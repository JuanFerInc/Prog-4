#ifndef DTVIAJE_H
#define DTVIAJE_H

#include "DtViajeBase.h"
#include "DtVehiculo.h"
#include "DtMonopatin.h"

class DtViaje : public DtViajeBase {
private:
	float precioTotal;
	DtVehiculo *vehiculo;              //Same abajo
public:

	//Constructora
	DtViaje();
	//DtViaje(fecha,duracion,distancia,precioTotal,vehiculo)
	DtViaje(DtFecha, int, int, float, DtVehiculo*);
	
    
	//Getters
    float getprecioTotal();
    DtVehiculo *getvehiculo();          //¿Pointer o no pointer? Eso es la cuestion
    

	
};
#endif
