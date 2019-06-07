#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>

#include "../Header/Mesa.h"
#include "../Header/TipoTransporte.h"

using namespace std;

class Empleado  {
private:
    int nroEmpleado;
    string nombre;
public:

//seters
	void setNroEmpleado(int nroEmpleado);
	void setNombre(string nombre);

//geters
	int getNroEmpleado();
	string getNombre();

	virtual ~Empleado() = 0;
};

#endif
