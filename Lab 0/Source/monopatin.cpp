#include "../Header/monopatin.h"


//Constructor
Monopatin::Monopatin(){}
Monopatin::Monopatin(bool tieneLuces) {
	this->tieneLuces = tieneLuces;
}
		//Get
bool Monopatin::gettieneLuces() {
	return this->tieneLuces;
}
		//Set
void Monopatin::settieneLuces(bool tieneLuces) {
	this->tieneLuces = tieneLuces;
}
		//Def
float Monopatin::darPrecioViaje(int duracion, int distancia) {
	float precio;
	
	if (tieneLuces) {
		precio = ((float)(0.5)*duracion) + (distancia*this->getprecioBase());

	}
	else {
		precio = distancia * this->getprecioBase();
	}
	return precio;
}


