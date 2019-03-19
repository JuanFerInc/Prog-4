#ifndef DTVIAJESBASE_H
#define DTVIAJESBASE_H

#include "DtFecha.h"

class DtViajeBase {


private:
	DtFecha fecha;
	int duracion;
	int distancia;
public:
	//Constructora
	DtViajeBase();
	DtViajeBase(DtFecha, int, int);
	//Get
	DtFecha getFecha();
	int getDuracion();
	int getDistancia();

	//Como es dt
	bool sonIguales(DtViajeBase* a_comparar);

	


};
#endif 