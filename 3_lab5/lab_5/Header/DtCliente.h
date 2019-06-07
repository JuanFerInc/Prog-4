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
	//contructor por copia
	DtCliente(const DtCliente &c);
	//geters
	string getTelefono();
	string getNombre();
	DtDireccion getDireccion();
};
#endif