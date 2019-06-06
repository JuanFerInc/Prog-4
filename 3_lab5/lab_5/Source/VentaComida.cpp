#include "../Header/VentaComida.h"


VentaComida::VentaComida(Comida* c, int cantidad) {
	this->cantidad = cantidad;
	this->linkComida = c;
}

bool VentaComida::ventaContieneComida(string codigo) {
	return sonIguales(codigo);
}

void VentaComida::incrementarCantidad(string codigo, int cantidad) {
	if (this->linkComida->sonIguales(codigo)) {
		this->aumentoCantidad(cantidad);
	}
}

void VentaComida::aumentoCantidad(int cantidad) {
	this->cantidad = this->cantidad + cantidad;
}

