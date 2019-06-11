#include "../Header/DtProductoMenu.h"

DtProductoMenu::DtProductoMenu(const DtProductoMenu &dt) {
	this->cantidad = dt.cantidad;
	this->codigo = dt.codigo;
}



int DtProductoMenu::getCantidad() const {
	return this->cantidad;

DtProductoMenu::DtProductoMenu(string codigo, int cantidad) {
	this->cantidad = cantidad;
	this->codigo = codigo;

}

int DtProductoMenu::getCantidad() const {
	return this->cantidad;
}

string DtProductoMenu::getCodigo() const {
	return this->codigo;
}
