#include "../Header/DtEmpleado.h"

DtEmpleado::DtEmpleado(string nombre, int nroEmp) {
	this->nombre = nombre;
	this->nroEmpleado = nroEmp;
}

int DtEmpleado::getNroEmpleado() const{
	return this->nroEmpleado;
}

string DtEmpleado::getNombre() const {
	return this->nombre;
}