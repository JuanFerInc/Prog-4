#include "../Header/Menu.h"

DtProducto* Producto::darDataType() {
	DtProducto* data = new DtProducto(this->getCodigo(), this->getDescripcion(), this->getPrecio());
	return data;
}
	
void Producto::darDeBajaComida() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->esContenidoEn.begin(); iter != this->esContenidoEn.begin(); iter++) {
		(*iter)->desvincularProductoDeMenu();
	}
}

