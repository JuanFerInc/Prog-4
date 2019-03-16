#include <string>
#include "../Header/usuario.h"


//Constructor
Usuario::Usuario() {

}

Usuario::Usuario(std::string ci, std::string nombre1, DtFecha fecha){
	cedula = ci;
	nombre = nombre1;
	fechaingreso = fecha;
	for (int i = 1; i < 100; i++) {
		Viajes[i] = NULL;
	}
}

//getters
std::string Usuario::getCedula(){
	return this->cedula;
}

std:: string Usuario::getNombre(){
	return this->nombre;
}

DtFecha Usuario::getFechaIngreso(){
	return this->fechaingreso;
}

//setters
void Usuario::setCedula(std::string ci){
	cedula = ci;
}

void Usuario::setNombre(std::string nomb1){
	nombre = nomb1;
}

void Usuario::setFechaIngreso(DtFecha fecha){
	fechaingreso = fecha;
}

//Otras
void Usuario::AgregarViaje(Viaje via){
	int i = 0;
	while((i<100) && (Viajes[i] != NULL)){
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
		Viajes[i] = NULL;
	}
}
//Destructor
Usuario:: ~Usuario() {
	for (int i = 0; i < 100; i++) {
		if (Viajes[i] != NULL) {
			delete Viajes[i];
		}
	}
}