#include "../Header/DtMenuVenta.h"
#include <iostream>
DtMenuVenta::DtMenuVenta(string codigo, string descripcion, int precio, int cantidad, set<DtProductoVenta*> productosDeMenu):DtMenu(codigo, descripcion, precio, productosDeMenu) {
	this->cantidad = cantidad;
}
int DtMenuVenta::getCantidad() {
	return this->cantidad;
}
void DtMenuVenta::print(ostream& out) {
	out << "El codigo es:" << this->codigo << endl;
	out << "La descripcion es:" << this->descripcion << endl;
	out << "El Precio Total es:" << this->precioTotal << endl;
	set<DtProductoVenta*>::iterator i;
	for (i = productosDeMenu.begin(); i != productosDeMenu.end(); i++) {
		DtProductoVenta *c = (*i);
		cout << "    " << c << endl;
	}
	cout << "Cantidad: " << cantidad << endl;
}
