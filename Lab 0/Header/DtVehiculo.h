#ifndef DTVEHICULO_H
#define DTVEHICULO_H

class DtMonopatin;

class DtVehiculo {
	private:
		int nroSerie;
		float porcentaje;
		float precioBase;
	public:
		//Constructor
		DtVehiculo();
		DtVehiculo(int , float , float);

		//Getters
		int getnroSerie() const;
		float getporcentajeBateria() const;
		float virtual getprecioBase() const;
};

#include "DtMonopatin.h"
#endif 