#include "../Header/Empleado.h"

//seters
void Empleado::setNroEmpleado(int nroEmpleado) {
	this->nroEmpleado = nroEmpleado;
}
void Empleado::setNombre(string nombre) {
	this->nombre = nombre;
}

//geters
int Empleado::getNroEmpleado() const {
	return this->nroEmpleado;
}
string Empleado::getNombre() const {
	return this->nombre;
}
