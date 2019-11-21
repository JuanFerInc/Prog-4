#include <string>
#include "../Header/usuario.h"


//Constructor
Usuario::Usuario() {

}

Usuario::Usuario(std::string ci, std::string nombre1, DtFecha fecha) {
	cedula = ci;
	nombre = nombre1;
	fechaingreso = fecha;
	for (int i = 0; i < 100; i++) {
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
bool Usuario::agregarViaje(Viaje* via) {
	bool insertado = false;
	int i = 0;
	while ((i < 100) && (Viajes[i] != NULL)) {
		i++;
	}
	if (i < 100) {
		Viajes[i] = via;
		insertado = true;
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
		if (Viajes[i] != NULL) {
			if (Viajes[i]->getfecha() == fechita) {
				delete Viajes[i];
				Viajes[i] = NULL;
			}
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

int Usuario::contarViajesEntre(const DtFecha& inicio, const DtFecha& fin) {
	int cantViajes = 0;
	for (int i = 0; i < 100; i++) {
		if (Viajes[i] != NULL) {
			if ((Viajes[i]->getfecha() < fin) && (Viajes[i]->getfecha() > inicio)) {
				cantViajes++;
			}
		}
	}
	return cantViajes;
}

Viaje** Usuario::arregloViajesMenores(const DtFecha& fechita, int cantViajes) {
	Viaje **nuevoViaje = NULL;
	int j = 0;
	if (cantViajes > 0) {
		nuevoViaje = new Viaje*[cantViajes];
		for (int i = 0; i < 100; i++) {
			if (Viajes[i] != NULL) {
				if (this->Viajes[i]->getfecha() < fechita) {
					nuevoViaje[j] = Viajes[i];

					j++;
				}
			}
		}
	}

	return nuevoViaje;
}

Viaje** Usuario::arregloViajesEntre(const DtFecha& inicio, const DtFecha& fin, int cantViajes) {
	Viaje** nuevoViaje = NULL;
	int j = 0;
	if (cantViajes > 0) {
		nuevoViaje = new Viaje * [cantViajes];
		for (int i = 0; i < 100; i++) {
			if (Viajes[i] != NULL) {
				if (this->Viajes[i]->getfecha() < fin && this->Viajes[i]->getfecha() > inicio) {
					nuevoViaje[j] = Viajes[i];

					j++;
				}
			}
		}
	}

	return nuevoViaje;
}


//Destructor
Usuario:: ~Usuario() {
	for (int i = 0; i < 100; i++) {
		if (Viajes[i] != NULL) {
			delete Viajes[i];
		}
	}
}