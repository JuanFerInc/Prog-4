#include "../header/DtDelivery.h"
#include <string>

TipoTransporte DtDelivery::getTransporte() {
	return(this->transporte);
}

void DtDelivery::print(std::ostream& out) {
	using namespace std;
	out << "numero de empleado: " << this->getNroEmpleado << endl;
	out << "nombre: " << this->getNombre << endl;
	out << "tipo de transporte: " << this->transporte << endl;
}