#ifndef VIAJE_H
#define VAIJE_H

#include <string>

#include "DtFecha.h"
#include "vehiculo.h"

class Viaje{
private:
	DtFecha fecha;
	int distancia, duracion;
	Vehiculo *viajaen;
public:
	//Constructors
	Viaje();
	Viaje(DtFecha, int, int, Vehiculo*);

	//getters
	DtFecha getfecha();
	int getdistancia();
	int getduracion();
	
	//setters
	void setfecha(DtFecha);
	void setdistancia(int);
	void setduracion(int);
	void setViajaEn(Vehiculo&);

	//Otras
	bool operator!=(Viaje);

	//Destructor
	~Viaje();

		
};


#endif