#include "../Header/Menu.h"


DtMenu* Menu::darDataType() {

	set<DtProductoVenta>datosProductos;

	set<MenuProducto*>::iterator ptr;

	//Obtengo cada producto del menu
	for (ptr = this->productosContenidos.begin(); ptr != this->productosContenidos.end(); ptr++) {
		MenuProducto *mp = *ptr;
		DtProductoVenta pv = mp->darInfo();
		datosProductos.insert(pv);
	}

	DtMenu *datamenu = new DtMenu(this->getCodigo(), this->getDescripcion(), this->getPrecio(), datosProductos);

	return datamenu;
}

void Menu::darDeBajaComida() {

}

void Menu::asociarmeAMenuProducto(MenuProducto *mp) {
	productosContenidos.insert(mp);
}

bool Menu::desvincularM() {
	set<MenuProducto*>::iterator iter;
	for (iter = this->productosContenidos.begin(); iter != this->productosContenidos.end(); iter++) {}
}