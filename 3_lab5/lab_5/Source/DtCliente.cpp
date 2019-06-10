#include "../Header/DtCliente.h"

DtCliente::DtCliente(const DtCliente &c) {
	this->direccion = c.direccion;
	this->telefono = c.telefono;
	this->nombre = c.nombre;
}

DtDireccion DtCliente::getDireccion() {
	return this->direccion;
}

string DtCliente::getNombre() {
	return this->nombre;
}

string DtCliente::getTelefono() {
	return this->telefono;
}