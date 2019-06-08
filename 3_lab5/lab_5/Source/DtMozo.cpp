
#include "../header/DtMozo.h"
#include <iostream>
using namespace std;

void DtMozo::print(std::ostream& out) {
	using namespace std;
	out << "numero de empleado: " << this->getNroEmpleado << endl;
	out << "nombre: " << this->getNombre << endl;
}

