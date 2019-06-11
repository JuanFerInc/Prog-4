#include "../header/DtApartamento.h"
#include <string>

DtDireccion::DtDireccion(string numero, string calle, string calleAdyacente) {
	this->calleAdyacente = calleAdyacente;
	this->nombreCalle = calle;
	this->numero = numero;
}


DtDireccion::DtDireccion(const DtDireccion &direccion) {
	this->nombreCalle = direccion.nombreCalle;
	this->numero = direccion.numero;
	this->calleAdyacente = direccion.calleAdyacente;
}

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