#include "../Header/VentaComida.h"

bool VentaComida::tieneMismo(string codigo) {
	return this->linkComida->sonIguales(codigo);
}

VentaComida::VentaComida(Comida* c, int cantidad) {
	this->cantidad = cantidad;
	this->linkComida = c;
}

bool VentaComida::ventaContieneComida(string codigo) {
	return linkComida->sonIguales(codigo);
}

void VentaComida::incrementarCantidad(string codigo, int cantidad) {
	if (this->linkComida->sonIguales(codigo)) {
		this->aumentoCantidad(cantidad);
	}
}

void VentaComida::aumentoCantidad(int cantidad) {
	this->cantidad = this->cantidad + cantidad;
}
