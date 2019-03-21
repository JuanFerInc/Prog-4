#include <string>
#include "../Header/viaje.h"

//Constructors
Viaje::Viaje(){}
Viaje::Viaje(DtFecha fechita, int di, int du, Vehiculo* vehiculo){
	fecha = fechita;
	distancia = di;
	duracion = du;
	viajaen = vehiculo;
}

//getters

DtFecha Viaje::getfecha(){
	return fecha;
}

int Viaje::getdistancia(){
	return distancia;
}

int Viaje::getduracion(){
	return duracion;
}


//setters

void Viaje::setfecha(DtFecha fechita){
	fecha = fechita;
}

void Viaje::setdistancia(int d){
	this->distancia = d;
}

void Viaje::setduracion(int d){
	this->duracion = d;
}


void Viaje::setViajaEn(Vehiculo &ve){
	*viajaen = ve;
}


//Otras
bool Viaje::operator!=(Viaje via){
	return !((this->fecha == via.fecha) && (this->distancia == via.distancia) && (this->duracion == via.duracion));
}

//Destructor
Viaje::~Viaje() {

}