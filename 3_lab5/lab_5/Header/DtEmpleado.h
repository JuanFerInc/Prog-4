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
	DtEmpleado();
	DtEmpleado(string nombre, int nroEmp);
//geters
	int getNroEmpleado() const;
	string getNombre() const;

	//DtAsignacionMesa asignarAuto();
};


#endif // !
