#ifndef MONOPATIN_H
#define MONOPATIN_H

#include "vehiculo.h"
#include "DtBicicleta.h"


class Monopatin: public Vehiculo{
	private:
		bool tieneLuces;
	public:	
		//Constructor
		Monopatin(bool tieneLuces);
		//Get
		bool gettieneLuces();
		//Set
		void settieneLuces(bool tieneLuces);
		//Def
		float darPrecioViaje(int duracion, int distancia);
}



#endif
