#ifndef DTMENU_H
#define DTMENU_H


#include "../Header/DtProductoVenta.h"

class DtProductoVenta;

class DtMenu : public DtComida {
protected:
	set<DtProductoVenta*> productosDeMenu;

public:
	DtMenu() = default;
	//Contructor por copia
	DtMenu(const DtMenu &m);

	DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta*>datosProductos);

	//geters

	set<DtProductoVenta*> getProductosDeMenu();
	
	
	virtual void print(ostream& out);
};


#endif // !DTMENU

