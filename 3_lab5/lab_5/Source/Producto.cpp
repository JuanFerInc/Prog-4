#include "../Header/Menu.h"

DtMenu Menu::darDataType() {

	set<DtProductoVenta>datosProductos;

	set<MenuProducto*>::iterator ptr;

	//Obtengo cada producot del menu
	for (ptr = this->productosContenidos.begin(); ptr != this->productosContenidos.end(); ptr++) {
		MenuProducto *mp = *ptr;
		DtProductoVenta pv = mp->darInfo();
		datosProductos.insert(pv);
	}

	DtMenu datamenu(this->getCodigo(), this->getDescripcion(), this->getPrecio(), datosProductos);

	return datamenu;
}
	
void Producto::darDeBajaComida() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->esContenidoEn.begin(); iter != this->esContenidoEn.begin(); iter++) {
		(*iter)->desvincular
	}
}
