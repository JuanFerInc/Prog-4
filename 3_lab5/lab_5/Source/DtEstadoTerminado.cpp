#include "../Header/DtEstadoTerminado.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtEstado.h"			
#include "../Header/DtComidaVendida.h"
#include <string>

DtEstadoTerminado::DtEstadoTerminado(string nombre, string telefono, DtHora hora, string etapa, set<DtComidaVendida*> comidasVendidas):DtEstado(etapa){
	this->nombre = nombre;
	this->telefono = telefono;
	this->hora = hora;
	this->comidasVendidas = comidasVendidas;
}
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

set<DtComidaVendida*> DtEstadoTerminado::getComidasVendidas() {
	return this->comidasVendidas;
}


//impresion
void DtEstadoTerminado::print(ostream& out) {
	out << "Etapa actual" << this->getEtapaActual() << endl;
	out << "El nombre es:" << this->nombre << endl;
	out << "El telefono es:" << this->telefono << endl;
	out << "La hora es:" << &this->hora << endl;

}
bool DtEstadoTerminado::operator<(const DtEstadoTerminado& d) const{
	if (this->telefono.compare(d.telefono) <= 0) {
		return true;
	}else { 
		return false;
	}

}