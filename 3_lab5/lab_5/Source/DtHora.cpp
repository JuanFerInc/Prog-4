#include "../Header/DtHora.h"

//Constructor por copia
DtHora::DtHora() {

}

DtHora::DtHora(int minuto, int hora){
	this->hora = hora;
	this->minuto = minuto;
}
DtHora::DtHora(const DtHora &hora) {
	this->hora = hora.hora;
	this->minuto = hora.minuto;
}

//geters
int DtHora::getMinuto() {
	return this->minuto;
}

int DtHora::getHora() {
	return this->hora;
}

bool DtHora::operator<(const DtHora& a) {
	if (a.hora < this->hora) {
		return false;
	}
	else {
		if (a.hora == this->hora) {
			if (a.minuto <= this->minuto) {
				return false;
			}
			else return true;
		}
		else return true;
	}
}


std::ostream& operator<<(std::ostream& out, DtHora*info) {
	info->print(out);
	return out;
}

void DtHora::print(ostream& out) {
	out << "La hora es:" << this->hora << endl;
	out << "Los minutos son" << this->minuto << endl;
}

DtHora DtHora::operator=(const DtHora& a) {
	this->hora = a.hora;
	this->minuto = a.minuto;
	return (*this);
}