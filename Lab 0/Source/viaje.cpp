#include "..viaje.h"
#include <string>


//Constructors
Viaje::Viaje(DtFecha fechita, int di, int du){
	fecha = fechita;
	distancia = di;
	duracion = du;
	*viajero = NULL;
	*viajaen = NULL;
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

void Viaje::setEsViajeDe(Usuario us){
	*viajero = us;
}

void Viaje::setViajaEn(Vehiculo ve){
	*viajaen = ve;
}


//Otras
bool Viaje::operator!=(Viaje via){
	return !((this->fecha == via.fecha) && (this->distancia == via.distancia) && (this->duracion == via.duracion))
}
