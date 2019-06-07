#include "../header/DtApartamento.h"
#include <string>
//getters

string DtApartamento::getNombreEdificio() {
    return (this->nombreEdificio);
}

string DtApartamento::getNumeroApartamento() {
    return (this->numeroApartamento);
}
// Contructor por copia
DtApartamento::DtApartamento (const DtApartamento &apart) {
    this->nombreEdificio= apart.nombreEdificio;
	this->numeroApartamento = apart.numeroApartamento;
}

std::ostream& operator<<(std::ostream& out, DtApartamento*info) {
	info->print(out);
	return out;
}

void DtApartamento::print(std::ostream& out) {
	using namespace std;
	out << "Edificio: " << this->getNombreEdificio() << endl;
	out << "Apartamento: " << this->getNumeroApartamento() << endl;
	
}

