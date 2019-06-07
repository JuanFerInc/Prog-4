#include "../header/DtApartamento.h"

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
    this->numeroApartamento=apart.numeroApartamento
}


