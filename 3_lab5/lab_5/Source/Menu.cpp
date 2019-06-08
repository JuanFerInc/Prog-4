#include "../Header/Menu.h"

Menu::Menu(string nombre, string descripcion):Comida(nombre,descripcion) {
}

set<MenuProducto* > Menu::getProductosContenidos() {
	return this->productosContenidos;
}

int Menu::getPrecio() {
	set<MenuProducto*>::iterator iter;
	int total = 0;
	for (iter = productosContenidos.begin(); iter != productosContenidos.end(); iter++) {
		total= total+(*iter)->getPrecio();
	}
	return round(total*0.9);
}

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
	set<MenuProducto*>::iterator iter;
	for (iter = productosContenidos.begin(); iter != productosContenidos.end(); iter++) {
		(*iter)->notificarProducto();
		delete (*iter); //peude ser que tenga que borrar del set o cambiar la forma de borrarlo
	}
	
}

void Menu::asociarmeAMenuProducto(MenuProducto *mp) {
	productosContenidos.insert(mp);
}

bool Menu::desvincularM(MenuProducto *mp) {
	set<MenuProducto*>::iterator iter;
	bool res = false;
	for (iter = productosContenidos.begin(); iter != productosContenidos.end(); iter++) {
		if (mp == *iter) {
			productosContenidos.erase(iter);
		}
	}

	return productosContenidos.empty();
	
}

DtComida *Menu::darDataVenta() {

}