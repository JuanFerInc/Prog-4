#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>


#include "../Header/TipoTransporte.h"


using namespace std;

class Empleado  {
private:
    int nroEmpleado;
    string nombre;
public:
	Empleado(string nombre, int nroEmpleado);
//seters
	void setNroEmpleado(int nroEmpleado);
	void setNombre(string nombre);

//geters
	int getNroEmpleado() const;
	string getNombre() const;

	virtual ~Empleado() {};
};

#endif
