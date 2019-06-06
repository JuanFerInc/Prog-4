#include "../Header/Comida.h"
#include <iostream>

using namespace std;

DtProducto Producto::darDataType() {
	DtProducto data(this->getCodigo(), this->getDescripcion(), this->getPrecio());
	return data;
}

DtMenu Menu::darDataType(){
	
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