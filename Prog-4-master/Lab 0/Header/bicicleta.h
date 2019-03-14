#ifndef BICICLETA_H
#define BICICLETA_H

#include "vehiculo.h"
#include "DtBicicleta.h"


class Bicicleta: public Vehiculo{
	private:
		TipoBici tipo;
		int cantCambios;
	public:	
		//Constructor
		Bicicleta(TipoBici tipo, int cantCambios);

		//Get
		TipoBici getTipo();
		int getcantCambios();

		//Set
		void setTipo(TipoBici tipo);
		void setcantCambios(int cantCambios);

		//Def
		float darPrecioViaje(int duracion, int distancia);
}



#endif
