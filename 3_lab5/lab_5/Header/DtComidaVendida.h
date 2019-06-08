#ifndef DTCOMIDAVENDIDA_H
#define DTCOMIDAVENDIDA_H

#include <iostream>

using namespace std;

class DtComidaVendida {
private:

	string nombre;
	int precio, cantidad;
public: 

	string getNombre();
	int getPrecio();
	int getPrecioTotal();
	int getCantidad();

	DtComidaVendida(int cantidad,string descripcion,int precio);
	void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, DtComidaVendida*info);

};



#endif

