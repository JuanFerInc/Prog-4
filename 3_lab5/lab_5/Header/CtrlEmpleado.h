#ifndef CTRLEMPLEADO_H
#define CTRLEMPLEADO_H	

#include <iostream>
#include <map>
#include <set>

#include "../Header/Empleado.h"
#include "../Header/IEmpleado.h"

using namespace std;

class CtrlEmpleado: public IEmpleado {
private:
	static CtrlEmpleado* instancia;
	map<int, Empleado> coleccionDeEmpleado;

	CtrlEmpleado();
public:
	static CtrlEmpleado* getInstance();
	set<int>* mesasDeMozo(int nroEmpleado);
	
};
#endif