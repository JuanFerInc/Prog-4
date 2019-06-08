#include "../Header/DtProductoMenu.h"

DtProductoMenu::DtProductoMenu(const DtProductoMenu &dt) {
	this->cantidad = dt.cantidad;
	this->codigo = dt.codigo;
}
DtProductoMenu::DtProductoMenu(string codigo, int cantidad) {
	this->cantidad = cantidad;
	this->codigo = codigo;
}

int DtProductoMenu::getCantidad() {
	return this->cantidad;
}

string DtProductoMenu::getCodigo() {
	return this->codigo;
}
