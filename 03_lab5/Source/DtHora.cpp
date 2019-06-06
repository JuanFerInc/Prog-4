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

bool DtHora::operator<(const DtHora& a) {
	if (a.hora < this->hora) {
		return false;
	}else{ 
		if (a.hora == this->hora) {
			if (a.minuto <= this->minuto) {
				return false;
			}
			else return true;
		}
		else return true;
}
