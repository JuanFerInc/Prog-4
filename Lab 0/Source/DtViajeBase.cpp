#include <string>

#include "../Header/DtViajeBase.h"


//Constructora
DtViajeBase::DtViajeBase() {

}

DtViajeBase::DtViajeBase(DtFecha fecha_arg, int duracion_arg, int distancia_arg) {
	fecha = fecha_arg;
	duracion = duracion_arg;
	distancia = distancia_arg;
}

DtViajeBase::DtViajeBase(const DtViajeBase& via) {
	this->fecha = via.fecha;
	this->duracion = via.duracion;
	this->distancia = via.distancia;
}
//Get
DtFecha DtViajeBase::getFecha(){
	return this->fecha;
}

int DtViajeBase::getDuracion(){
	return this->duracion;
}

int DtViajeBase::getDistancia(){
	return this->distancia;
}

