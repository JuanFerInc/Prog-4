#include "../Header/DtProductoMenu.h"

DtProductoMenu::DtProductoMenu(const DtProductoMenu &dt) {
	this->cantidad = dt.cantidad;
	this->codigo = dt.codigo;
}
int DtProductoMenu::getCantidad() {
	return this->cantidad;
}

string DtProductoMenu::getCodigo() {
	return this->codigo;
}
