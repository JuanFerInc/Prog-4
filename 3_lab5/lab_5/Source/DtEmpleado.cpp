#include "../header/DtEmpleado.h"
#include <string>

int DtEmpleado::getNroEmpleado() { 
	return (this->nroEmpleado);
}

string DtEmpleado::getNombre() {
	return (this->nombre);
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