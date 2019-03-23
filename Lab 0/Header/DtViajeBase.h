
#ifndef DTVIAJEBASE_H
#define DTVIAJEBASE_H

#include "DtFecha.h"

class DtViajeBase {


private:
	DtFecha fecha;
	int duracion;
	int distancia;
public:
	//Constructora
	DtViajeBase();
	//DtViajeBase(fecha,duracion,distnacia)
	DtViajeBase(DtFecha, int, int);
	
	DtViajeBase(const DtViajeBase&);

	//Get
	DtFecha getFecha();
	int getDuracion();
	int getDistancia();



};

#ifndef DTVIAJEBASE_H
#define DTVIAJEBASE_H

#include "DtFecha.h"

class DtViajeBase {


private:
	DtFecha fecha;
	int duracion;
	int distancia;
public:
	//Constructora
	DtViajeBase();
	//DtViajeBase(fecha,duracion,distnacia)
	DtViajeBase(DtFecha, int, int);
	
	DtViajeBase(const DtViajeBase&);

	//Get
	DtFecha getFecha();
	int getDuracion();
	int getDistancia();



};
#endif 

