#include "../Header/DtProductoVenta.h"

#include <string>
#include <iostream>

DtProductoVenta::DtProductoVenta(DtProducto producto, int cantidad) : DtProducto(producto, cantidad)) {
this->cantidad = cantidad;

}
void DtProductoVenta::operator<<(ostream& out){
	out << "La descripcion es:" << this->descripcion << endl;
	out << "El Precio Total es:" << this->precioTotal << endl;
	out << "La cantidad es:" << this->cantidad << endl;
}