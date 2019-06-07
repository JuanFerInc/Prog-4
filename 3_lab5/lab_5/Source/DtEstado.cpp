#include "../Header/DtEstado.h"

DtEstado::DtEstado(const DtEstado &e){
	this->etapaActual = e.etapaActual;
}

DtEstado::DtEstado(string c) {
	this->etapaActual = c;
}

string DtEstado::getEtapaActual() const{
	return this->etapaActual;
}