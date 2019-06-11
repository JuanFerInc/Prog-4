#include "../Header/DtProductoVenta.h"

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

void DtProductoVenta::operator<<(ostream& out){
	out << "La descripcion es:" << this->descripcion << endl;
	out << "El Precio Total es:" << this->precioTotal << endl;
	out << "La cantidad es:" << this->cantidad << endl;
}

