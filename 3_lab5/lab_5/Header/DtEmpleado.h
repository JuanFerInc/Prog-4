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
	friend std::ostream& operator<<(std::ostream& out, DtEmpleado*info);
	virtual void print(std::ostream& out);

	DtAsignacionMesa asignarAuto();
};


#endif // !
