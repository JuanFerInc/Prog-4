#include "../Header/DtCliente.h"
#include <string>

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

std::ostream& operator<<(std::ostream& out, DtCliente*info) {
	info->print(out);
	return out;
}

void DtCliente::print(std::ostream& out) {
	using namespace std;
	out << "telefono: " << this->telefono << endl;
	out << "nombre: " << this->nombre << endl;
	out << "direccion: " << &this->direccion << endl;
}