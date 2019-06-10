#include "../Header/DtProducto.h"

#include <string>
#include <iostream>

using namespace std;

DtProducto::DtProducto(const DtProducto& producto) :DtComida(producto.getCodigo(), producto.getDescripcion(), producto.getPrecioTotal()) {
}
DtProducto::DtProducto(string codigo, string descripcion, int precioTotal) :DtComida(codigo, descripcion, precioTotal) {
}

void DtProducto::operator<<(ostream& out) {
	out << "El codigo es:" << this->codigo << endl;
	out << "La descripcion es:" << this->descripcion << endl;
	out << "El Precio Total es:" << this->precioTotal << endl;
}