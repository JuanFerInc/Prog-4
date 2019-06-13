#include "../Header/DtCliente.h"				//Hay que ver lo de direccion*
#include "../Header/DtDireccion.h"
DtCliente::DtCliente(string telefono, string nombre, DtDireccion*direccion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
}
DtCliente::DtCliente(const DtCliente &c) {
	this->direccion = c.direccion;
	this->telefono = c.telefono;
	this->nombre = c.nombre;
}

DtDireccion* DtCliente::getDireccion() {
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
	
	out << "telefono: " << this->telefono << endl;
	out << "nombre: " << this->nombre << endl;
	out << "direccion: " << endl << this->direccion << endl;
}