
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
		//Bicicleta(nroSerie,porcentajeBateria,precioBase,tipoBici,cantCambios)
		Bicicleta(int,float,float,TipoBici, int);

		//Get
		TipoBici getTipo();
		int getcantCambios();

		//Set
		void setTipo(TipoBici tipo);
		void setcantCambios(int);

		//Def
		float darPrecioViaje(int, int);
}
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
		//Bicicleta(nroSerie,porcentajeBateria,precioBase,tipoBici,cantCambios)
		Bicicleta(int,float,float,TipoBici, int);

		//Get
		TipoBici getTipo();
		int getcantCambios();

		//Set
		void setTipo(TipoBici tipo);
		void setcantCambios(int);

		//Def
		float darPrecioViaje(int, int);
};


#endif