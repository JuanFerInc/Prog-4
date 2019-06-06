#ifndef MENUPRODUCTO_H
#define MENUPRODUCTO_H	

#include "../Header/DtProductoVenta.h"
#include "../Header/Menu.h"
#include "../Header/Producto.h"

using namespace std;

class MenuProducto {
private:
	Menu* linkMenu;
	Producto* linkProducto;
	int cantidad;

public:
	//seter
	void setCantidad(int cant);
	//geter
	int getCantidad();
	DtProducto getDtProducto();
	
	//Otras
	DtProductoVenta darInfo();

};
#endif