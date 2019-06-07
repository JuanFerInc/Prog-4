#include "../Header/DtMenu.h"

#include <string>
#include <iostream>

DtMenu::DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos) : DtComida(codigo, descripcion, precioTotal) {
	this->productosDeMenu = datosProductos;
}
//Constructor por copia
DtMenu::DtMenu(const DtMenu &m):DtComida(m.getCodigo(), m.getDescripcion(), m.getPrecioTotal()) {
	this->productosDeMenu = m.productosDeMenu;
	
}

void DtMenu::print(std::ostream& out) {
	out << "El codigo es:" << this->codigo << endl;
	out << "La descripcion es:" << this->descripcion << endl;
	out << "El Precio Total es:" << this->precioTotal << endl;
	set<DtProductoVenta>::iterator i;
	for (i = productosDeMenu.begin(); i != productosDeMenu.end(); i++) {
		DtProductoVenta c = (*i);
		cout << "    " << c << endl;
	}
}