#include <iostream>
#include "../Header/MenuProducto.h"
#include "../Header/Menu.h"
#include "../Header/DtProductoVenta.h"
#include "../Header/DtProducto.h"
#include "../Header/Producto.h"

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
int MenuProducto::getPrecio() const {
	return (linkProducto->getPrecio()*this->cantidad);
}
int MenuProducto::getCantidad() {
	return this->cantidad;
}

DtProductoVenta *MenuProducto::darInfo() {
	DtProducto *p = linkProducto->darDataType();
	DtProducto producto = *p;
	DtProductoVenta *datapv = new DtProductoVenta(producto, this->cantidad);

	delete p;
	return datapv;

}

DtProducto *MenuProducto::getDtProducto() {
	return this->linkProducto->darDataType();
}


void MenuProducto::desvincularProductoDeMenu(){
	if (this->linkMenu->desvincularM(this)) {
		delete linkMenu;
	}
}
void MenuProducto::notificarProducto() {
	linkProducto->desvincular(this);

}