#ifndef DTCOMIDAVENDIDA_H
#define DTCOMIDAVENDIDA_H

#include <iostream>

using namespace std;

class DtComidaVendida {
private:

	string nombre;
	int precio, precioTotal, cantidad;
public: 

	string getNombre();
	int getPrecio();
	int getPrecioTotal();
	int getCantidad();

};



#endif

