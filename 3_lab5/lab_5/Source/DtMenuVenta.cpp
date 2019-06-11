#include "../Header/DtMenuVenta.h"

DtMenuVenta::DtMenuVenta(string codigo, string descripcion, int precio, int cantidad, set<DtProductoVenta> productosDeMenu):DtMenu(codigo, descripcion, precio, productosDeMenu) {
	this->cantidad = cantidad;
}
int DtMenuVenta::getCantidad() {
	return this->cantidad;
}