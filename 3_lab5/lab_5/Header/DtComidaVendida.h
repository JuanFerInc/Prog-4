#ifndef DTCOMIDAVENDIDA_H
#define DTCOMIDAVENDIDA_H

#include <iostream>
#include <string>

using namespace std;

class DtComidaVendida {
private:

	string nombre;
	int precio, cantidad;
public: 
	DtComidaVendida(int cantidad, string descripcion, int precio);
	DtComidaVendida(const DtComidaVendida& dcv);


	string getNombre();
	int getPrecio();
	int getPrecioTotal();
	int getCantidad();

	friend std::ostream& operator<<(std::ostream& out, DtComidaVendida *info);
	void print(ostream& out);
	bool operator<(const DtComidaVendida& d)const;
	
};



#endif

