#ifndef DTCOMIDA_H
#define DTCOMIDA_H

#include <map>

using namespace std;

class DtComida {
private:
	string codigo, descripcion;
	int precioTotal;

public:
	string getCodigo();
	string getDescripcion();
	int getPrecioTotal();
	

};

class DtMenu: public DtComida {
private:
	map<string, DtProductoVentas> ProductosDeMenu;

public:
	map<string, DtProductoVentas> getProductosDeMenu();

};

class DtMenuVentas: public DtMenu {
private:
	int cantidad;

public:
	int getCantidad();

};


class DtProducto : public DtComida {
private:

};

class DtProductoVentas : public DtProducto {
private:
	int cantidad;

public:
	int getCantidad();
};


#endif