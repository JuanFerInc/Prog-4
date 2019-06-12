
#define _CRT_SECURE_NO_WARNINGS
#include "../Header/DtEmpleado.h"
#include <string>

DtEmpleado::DtEmpleado() {

}
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
std::ostream& operator<<(std::ostream& out, DtEmpleado*info) {
	info->print(out);
	return out;
}

void DtEmpleado::print(std::ostream& out) {
	using namespace std;
	out << "numero de empleado: " << this->nroEmpleado << endl;
	out << "nombre: " << this->nombre << endl;
}