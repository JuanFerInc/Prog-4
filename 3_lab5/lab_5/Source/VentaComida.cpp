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


DtComida* VentaComida::pedirDatatypeAComida() {
	return (this->linkComida->darDataType());
}

bool VentaComida::esMayor(string codigo, int cantidad) {
	if (this->linkComida->sonIguales(codigo)) {
		return (this->cantidad > cantidad);
	}
	return false;
}

void VentaComida::bajarCantidad(string codigo, int cantidad) {
	if (this->linkComida->sonIguales(codigo)) {
		this->cantidad = this->cantidad - cantidad;
	}
}

VentaComida* VentaComida::esComidaAEliminar(string codigo) {
	if (this->linkComida->sonIguales()) {
		return this;
	}
	return NULL;
}

DtComidaVendida* VentaComida::darDtComidayCantidad() {
	int cantidad = this->getCantidad();
	DtComida* data = this->linkComida->darDataType();
	int precioTotal = cantidad * data->getPrecioTotal();
	DtComidaVendida* res = new DtComidaVendida(cantidad, data->getDescripcion(), data->getPrecioTotal);
	return res;
}

void VentaComida::incrementarCantidadUnidadesVendidas() {
	this->linkComida->incrementarCantidadUnidadesVendidas(this->cantidad);
}

//Venta a Domicilio

int VentaComida::darPrecio() {
	int p = this->linkComida->getPrecio();
	int cant = this->cantidad;
	return cant * p;
}

DtComidaVendida VentaComida::pedirDatatypeDtComidaVendida() {
	return DtComidaVendida(this->cantidad, this->linkComida->getDescripcion(), this->linkComida->getPrecio());
}