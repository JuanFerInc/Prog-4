#ifndef DTCLIENTE_H
#define DTCLIENTE_H	

#include <iostream>
#include "../Header/DtDireccion.h"

using namespace std;

class DtCliente {
private:
	string telefono, nombre;
	DtDireccion direccion;

public:
	string getTelefono();
	string getNombre();
	DtDireccion getDireccion();
};
#endif