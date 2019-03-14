#include "..usuario.h"
#include <string>

//Constructor
Usuario::Usuario(string ci, string nombre1, DtFecha fecha){
	cedula = ci;
	nombre = nombre1;
	fechaingreso = fecha;
	for(int i=1, i<100 , i++){
		*Viajes[i] = NULL;
	}
}

//getters
string Usuario::getCedula(){
	return this->cedula;
}

string Usuario::getNombre(){
	return this->nombre;
}

DtFecha Usuario::getFechaIngreso(){
	return this->fechaingreso;
}

//setters
void Usuario::setCedula(string ci){
	cedula = ci;
}

void Usuario::setNombre(string nomb1){
	nombre = nomb1;
}

void Usuario::setFechaIngreso(DtFecha fecha){
	fechaingreso = fecha;
}

//Otras
void Usuario::AgregarViaje(Viaje via){
	int i = 0;
	while((i<100) && (*Viajes[i] != NULL)){
		i++;
	}
	if (i<100){
		*Viajes[i] = via;
	}
}

void Usuario::EliminarViaje(Viaje via){
	int i = 0;
	while((i<100) && (*Viajes[i] != via)){
		i++;
	}
	if (i<100){
		*Viajes[i] = NULL;
	}
}