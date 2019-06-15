#include "../Header/DtMenu.h"
#include "../Header/DtProductoVenta.h"
#include <string>
#include <iostream>

DtMenu::DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta*>datosProductos) : DtComida(codigo, descripcion, precioTotal) {
	this->productosDeMenu = datosProductos;
}

//Constructor por copia
DtMenu::DtMenu(const DtMenu &m):DtComida(m.getCodigo(), m.getDescripcion(), m.getPrecioTotal()) {
	this->productosDeMenu = m.productosDeMenu;
	
}

set<DtProductoVenta*> DtMenu::getProductosDeMenu() {
	return this->productosDeMenu;
}

void DtMenu::print(std::ostream& out) {
	out << "El codigo es: " << this->codigo << endl;
	out << "La descripcion es: " << this->descripcion << endl;
	out << "El Precio Total es: " << this->precioTotal << endl;
	set<DtProductoVenta*>::iterator i;
	cout << endl;
	cout << "================================================== " << endl;
	for (i = productosDeMenu.begin(); i != productosDeMenu.end(); i++) {
		cout << endl;
		cout << (*i) << endl;
	}
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}