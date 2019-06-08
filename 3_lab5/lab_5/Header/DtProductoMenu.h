#ifndef DTPRODUCTOMENU_H
#define DTPRODUCTOMENU_H	

#include <iostream>

using namespace std;

class DtProductoMenu {
private:
	string codigo;
	int cantidad;

public:
	//const
	DtProductoMenu(const DtProductoMenu &dt);
	DtProductoMenu(string codigo, int cantidad);

	//Get
	string getCodigo() const;
	int getCantidad() const;
};
#endif