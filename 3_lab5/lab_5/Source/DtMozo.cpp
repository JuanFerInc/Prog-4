#include "../header/DtMozo.h"
#include "../Header/DtEmpleado.h"
#include <iostream>
#include <string>

using namespace std;

DtMozo::DtMozo():DtEmpleado(){

}
DtMozo::DtMozo(int nroEmpleado, string nombre) :DtEmpleado(nombre, nroEmpleado) {

}
DtMozo::DtMozo(const DtMozo & dtmozo):DtEmpleado(dtmozo.getNombre(),dtmozo.getNroEmpleado() ) {

}

void DtMozo::print(std::ostream& out) {
	using namespace std;
	out << "numero de empleado: " << this->getNroEmpleado() << endl;
	out << "nombre: " << this->getNombre() << endl;
}
