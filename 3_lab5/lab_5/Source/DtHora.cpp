#include "../Header/DtHora.h"

DtHora::DtHora(const DtHora &hora) {
	this->hora = hora.hora;
	this->minuto = hora.minuto;
}

int DtHora::getMinuto() {
	return this->minuto;
}

int DtHora::getHora() {
	return this->hora;
}
