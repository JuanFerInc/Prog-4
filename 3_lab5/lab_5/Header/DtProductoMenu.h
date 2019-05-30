#ifndef DTPRODUCTOMENU_H
#define DTPRODUCTOMENU_H	

#include <iostream>

using namespace std;

class DtProductoMenu {
private:
	string codigo;
	int cantidad;

public:
	string getCodigo();
	int getCantidad();
};
#endif