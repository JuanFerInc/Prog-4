#include "../Header/DtEstadoTerminado.h"
#include <string>

//constructor por copia
DtEstadoTerminado::DtEstadoTerminado(const DtEstadoTerminado &dtterm):DtEstado(dtterm.getEtapaActual()) {
	this->comidasVendidas = dtterm.comidasVendidas;
	this->nombre = dtterm.nombre;
	this->telefono = dtterm.telefono;
	this->hora = DtHora(dtterm.hora);
}

//geters
string DtEstadoTerminado::getNombre() {
	return this->nombre;
}

string DtEstadoTerminado::getTelefono() {
	return this->telefono;
}

DtHora DtEstadoTerminado::getHora() {
	return this->hora;
}

set<DtComidaVendida> DtEstadoTerminado::getComidasVendidas() {
	return this->comidasVendidas;
}
//impresion
void DtEstadoTerminado::print(ostream& out){
	out << "sdasd" << this->getEtapaActual() << endl;
	out << "El nombre es:" << this->nombre << endl;
	out << "El telefono es:" << this->telefono << endl;
	out << "La hora es:" << this->hora.getHora() << endl;
	out << "Los minutos son:" << this->hora.getMinuto() << endl;
	
}
