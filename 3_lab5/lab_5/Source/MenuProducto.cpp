#include <iostream>
#include "../Header/MenuProducto.h"

using namespace std;

MenuProducto::MenuProducto(Menu *m, int cantidad,Producto *p) {
	this->linkMenu = m;
	this->cantidad = cantidad;
	this->linkProducto = p;

	m->asociarmeAMenuProducto(this);

}
DtProductoVenta MenuProducto::darInfo() {
	DtProducto producto = linkProducto->darDataType();
	

	DtProductoVenta datapv(producto, this->cantidad);

	return datapv;

}

DtProducto MenuProducto::getDtProducto() {

}


void MenuProducto::desvincularProductoDeMenu(){
	if (this->linkMenu->desvincularM(this)) {
		delete linkMenu;
	}
	

}