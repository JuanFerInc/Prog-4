#include <iostream>
#include "../Header/MenuProducto.h"

using namespace std;

MenuProducto::MenuProducto(Menu *m, int cantidad,Producto *p) {
	this->linkMenu = m;
	this->cantidad = cantidad;
	this->linkProducto = p;

	m->asociarmeAMenuProducto(this);

}
void MenuProducto::setCantidad(int cant) {
	this->cantidad = cant;
}
int MenuProducto::getPrecio() {
	return (linkProducto->getPrecio()*this->cantidad);
}
int MenuProducto::getCantidad() {
	return this->cantidad;
}

DtProductoVenta MenuProducto::darInfo() {
	DtProducto *p = linkProducto->darDataType();
	DtProducto producto = *p;
	DtProductoVenta datapv(producto, this->cantidad);

	delete p;
	return datapv;

}

DtProducto MenuProducto::getDtProducto() {

}


void MenuProducto::desvincularProductoDeMenu(){
	if (this->linkMenu->desvincularM(this)) {
		delete linkMenu;
	}
}
void MenuProducto::notificarProducto() {
	linkProducto->desvincular(this);

}