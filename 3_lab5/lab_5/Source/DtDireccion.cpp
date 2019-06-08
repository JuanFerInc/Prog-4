#include "../header/DtApartamento.h"
#include <string>

string DtDireccion::getNombreCalle() {
	return(this->nombreCalle);
}

string DtDireccion::getNumero() {
	return (this->numero);
}

string DtDireccion::getCalleAdyacente() {
	return (this->calleAdyacente);
}

std::ostream& operator<<(std::ostream& out, DtDireccion*info) {
	info->print(out);
	return out;
}

void DtDireccion::print(std::ostream& out) {
	using namespace std;
	out << "nombre calle: " << this->nombreCalle << endl;
	out << "numero: " << this->numero << endl;
	out << "calle adyacente: " << this->calleAdyacente << endl;
}