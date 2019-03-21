#include <string>
#include "../Header/usuario.h"


//Constructor
Usuario::Usuario() {

}

Usuario::Usuario(std::string ci, std::string nombre1, DtFecha fecha) {
	cedula = ci;
	nombre = nombre1;
	fechaingreso = fecha;
	for (int i = 1; i < 100; i++) {
		Viajes[i] = NULL;
	}
}

//getters
std::string Usuario::getCedula() {
	return this->cedula;
}

std::string Usuario::getNombre() {
	return this->nombre;
}

DtFecha Usuario::getFechaIngreso() {
	return this->fechaingreso;
}

//setters
void Usuario::setCedula(std::string ci) {
	cedula = ci;
}

void Usuario::setNombre(std::string nomb1) {
	nombre = nomb1;
}

void Usuario::setFechaIngreso(DtFecha fecha) {
	fechaingreso = fecha;
}

//Otras
bool Usuario::agregarViaje(Viaje via) {
	int i = 0;
	bool insertado = false;
	while ((i < 100) && (Viajes[i] != NULL)) {
		i++;
	}
	if (i < 100) {
		insertado = true;
		*Viajes[i] = via;
	}
	return insertado;
}

void Usuario::eliminarViaje(Viaje via) {
	int i = 0;
	while ((i < 100) && (*Viajes[i] != via)) {
		i++;
	}
	if (i < 100) {
		delete Viajes[i];
		Viajes[i] = NULL;
	}
}
void Usuario::eliminarViaje(DtFecha fechita) {
	for (int i = 0; i < 100; i++) {
		if (Viajes[i]->getfecha() == fechita) {
			delete Viajes[i];
			Viajes[i] = NULL;
		}
	}
}

int Usuario::contarViajes(const DtFecha& fechita) {
	int cantViajes = 0;
	for (int i = 0; i < 100; i++) {
		if (Viajes[i] != NULL) {
			if (Viajes[i]->getfecha() < fechita) {
				cantViajes++;
			}
		}
	}
	return cantViajes;
}

DtViaje** Usuario::arregloViajesMenores(const DtFecha& fechita, int cantViajes) {
	DtViaje **nuevoViaje = new DtViaje*[cantViajes];
	int j = 0;

	for (int i = 0; i < 100; i++) {
		if (this->Viajes[i]->getfecha() < fechita) {
			Vehiculo *ptrVehiculo = Viajes[i]->getviajaen();
			
			DtVehiculo vehiculo(ptrVehiculo->getnroSerie(),ptrVehiculo->getporcentajeBateria(),ptrVehiculo->getprecioBase());
			
			*nuevoViaje[j] = DtViaje(Viajes[i]->getfecha(),Viajes[i]->getduracion, Viajes[i]->getdistancia(), ptrVehiculo->getprecioBase(), vehiculo);

			j++;
		}

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