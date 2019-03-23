#ifndef MONOPATIN_H
#define MONOPATIN_H

#include "vehiculo.h"
#include "DtBicicleta.h"


class Monopatin: public Vehiculo{
	private:
		bool tieneLuces;
	public:	
		//Constructor
		Monopatin();
		//Monopatin(nroSerie,porcentajeBateria,precioBase,tieneLuces)
		Monopatin(int, float, float,bool);
		//Get
		bool gettieneLuces();
		//Set
		void settieneLuces(bool );
		//Def
		float darPrecioViaje(int , int );
};
#endif