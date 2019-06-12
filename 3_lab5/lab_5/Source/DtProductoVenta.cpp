#include "../Header/DtProductoVenta.h"		//Revisar el this->
#include "../Header/DtProducto.h"
#include "../Header/DtComida.h"

#include <string>
#include <iostream>

DtProductoVenta::DtProductoVenta(DtProducto producto, int cantidad):DtProducto(producto.getCodigo(), producto.getDescripcion(), producto.getPrecioTotal()) {
	this->cantidad = cantidad;
}

DtProductoVenta::DtProductoVenta(string codigo, string descripcion, int precio, int cantidad):DtProducto(codigo, descripcion, precio) {
	this->cantidad = cantidad;
}

int DtProductoVenta::getCantidad() {
	return this->cantidad;
}

void DtProductoVenta::print(std::ostream& out) {
	using namespace std;
	out << "Codigo: " << this->codigo << endl;
	out << "descripcion: " << this->descripcion << endl;
	out << "precio total " << this->precioTotal << endl;
	out << "cantidad " << this->cantidad << endl;
}
bool DtProductoVenta::operator<(const DtProductoVenta& d)const {
	if (this->codigo.compare(d.codigo) <= 0) {
		return true;
	}
	else {
		return false;
	}
}