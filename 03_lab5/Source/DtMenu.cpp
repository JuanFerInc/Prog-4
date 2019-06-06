#include "../Header/DtMenu.h"

DtMenu::DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos) : DtComida(codigo, descripcion, precioTotal) {
	this->productosDeMenu = datosProductos;
}
