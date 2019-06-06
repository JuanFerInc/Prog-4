#include <iostream>
#include "../Header/MenuProducto.h"

using namespace std;

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