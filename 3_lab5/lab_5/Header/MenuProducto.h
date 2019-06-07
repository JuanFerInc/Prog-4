#ifndef MENUPRODUCTO_H
#define MENUPRODUCTO_H	

#include "../Header/DtProductoVenta.h"
#include "../Header/Menu.h"

using namespace std;
class Producto;


class MenuProducto {
private:
	Menu* linkMenu;
	Producto* linkProducto;
	int cantidad;

public:
	//Constructor
	MenuProducto(Menu* m, int cantidad,Producto* p);
	//seter
	void setCantidad(int cant);
	//geter
	int getPrecio();
	int getCantidad();
	DtProducto getDtProducto();
	
	//Otras
	DtProductoVenta darInfo();
	void desvincularProductoDeMenu();
	//notifica al producto que tiene que desvincularse del mp
	void notificarProducto();



};


#include "../Header/Producto.h"
#endif