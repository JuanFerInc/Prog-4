#include "../Header/DtProducto.h"
#include "../Header/DtComida.h"
#include <string>
#include <iostream>

using namespace std;

DtProducto::DtProducto(const DtProducto& producto) :DtComida(producto.getCodigo(), producto.getDescripcion(), producto.getPrecioTotal()) {
}
DtProducto::DtProducto(string codigo, string descripcion, int precioTotal) :DtComida(codigo, descripcion, precioTotal) {
}


void DtProducto::print(std::ostream& out) {
	using namespace std;
	out << "Codigo: " << this->codigo << endl;
	out << "descripcion: " << this->descripcion << endl;
	out << "precio total " << this->precioTotal << endl;
}
bool DtProducto::operator<(const DtProducto& d)const {
	if (this->codigo.compare(d.codigo) <= 0) {
		return true;
	}
	else {
		return false;
	}
}