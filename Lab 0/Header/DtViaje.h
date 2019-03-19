#ifndef DTVIAJE_H
#define DTVIAJE_H

#include "DtViajesBase.h"
#include "DtVehiculo.h"

class DtViaje : public DtViajeBase {
private:
	float precioTotal;
	DtVehiculo vehiculo;
public:

	//Constructora
	DtViaje();
	DtViaje(DtFecha, int, int, float, DtVehiculo);
	//Como es dt
	bool sonIguales(DtViaje* a_comparar);
};
#endif