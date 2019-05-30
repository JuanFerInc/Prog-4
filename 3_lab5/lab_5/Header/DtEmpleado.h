#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H	

#include <iostream>
#include "../Header/TipoTransporte.h"


using namespace std;

class DtEmpleado {
private:

	int nroEmpleado;
	string nombre;

public:
	int getNroEmpleado();
	string getNombre();

};

class DtDelivery : public DtEmpleado {
private:
	TipoTransporte transporte;
public:
	TipoTransporte getTransporte();
};

class DtMozo :public DtEmpleado {
};

#endif // !
