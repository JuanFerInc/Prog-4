#include "../Header/DtFecha.h"

DtFecha::DtFecha(const DtFecha &fecha) {
	this->mes = fecha.mes;
	this->dia = fecha.dia;
	this->anio = fecha.anio;
}
int DtFecha::getDia() {
	return this->dia;
}
int DtFecha::getMes() {
	return this->mes;
}
int DtFecha::getAnio() {
	return this->anio;
}