#include "../Header/Producto.h"


Producto::Producto(string codigo, string descripcion, int precio) :Comida(codigo, descripcion) {

}
void Producto::asociarAMenu(Menu *m, int cantidad) {
	MenuProducto *mp = new MenuProducto(m, cantidad,this);
	esContenidoEn.insert(mp);

}

DtProducto* Producto::darDataType() {
	DtProducto* data = new DtProducto(this->getCodigo(), this->getDescripcion(), this->getPrecio());
	return data;
}
	

void Producto::darDeBajaComida() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->esContenidoEn.begin(); iter != this->esContenidoEn.begin(); iter++) {
		(*iter)->desvincularProductoDeMenu();
		delete (*iter);//posible mismo error que en menu
	}
}

void Producto::desvincular(MenuProducto *mp) {
	set<MenuProducto*>::iterator iter;
	bool found = false;
	iter = this->esContenidoEn.begin();
	while (!found && (iter != esContenidoEn.end())) {
		if (*iter == mp) {
			found = true;
			esContenidoEn.erase(iter);
		}
	}
}
DtComida *Producto::darDataVenta() {
	DtProductoVenta *res = new DtProductoVenta(this->codigo, this->descripcion, this->getPrecio(), this->cantitatUnidadesFacturadas);
	return res;
}