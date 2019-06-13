#include "../Header/DtApartamento.h"
#include "../Header/DtDireccion.h"
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

DtApartamento::DtApartamento(string nombreEdificio, string numeroApart, string calle, string adyacente, string numeroPuerta):DtDireccion(numeroPuerta, calle, adyacente) {
	this->nombreEdificio = nombreEdificio;
	this->numeroApartamento = numeroApart;
}

void DtApartamento::print(std::ostream& out) {
	using namespace std;
	out << "nombre calle: " << this->getNombreCalle() << endl;
	out << "numero: " << this->getNumero() << endl;
	out << "calle adyacente: " << this->getCalleAdyacente() << endl;
	out << "Edificio: " << this->nombreEdificio << endl;
	out << "Apartamento: " << this->numeroApartamento << endl;

}
