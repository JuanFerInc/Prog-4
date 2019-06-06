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
//geters
	int getNroEmpleado();
	string getNombre();

};


#endif // !
