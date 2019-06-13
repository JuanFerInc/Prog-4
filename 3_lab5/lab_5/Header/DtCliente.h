#ifndef DTCLIENTE_H
#define DTCLIENTE_H	

#include <iostream>
#include <string>
#include "../Header/DtDireccion.h"

using namespace std;

class DtCliente {
private:
	string telefono, nombre;
	DtDireccion* direccion;

public:
	DtCliente() {};
	//contructor por copia
	DtCliente(const DtCliente &c);
	DtCliente(string telefono, string nombre, DtDireccion*direccion);
	//geters
	string getTelefono();
	string getNombre();
	DtDireccion *getDireccion();

	friend ostream& operator<<(::ostream& out, DtCliente *info);
	void print(ostream& out);
};
#endif