#include "../Header/bicicleta.h"

		//Constructor
Bicicleta::Bicicleta(int nroSerie, float porcentajeBateria, float precioBase, TipoBici tipo, int cantCambios) :Vehiculo(nroSerie, porcentajeBateria, precioBase) {
	this->tipo = tipo;
	this->cantCambios = cantCambios;
}

		//Get
TipoBici Bicicleta::getTipo() {
	return this->tipo;
}
int Bicicleta::getcantCambios() {
	return this->cantCambios;
}

		//Set
void Bicicleta::setTipo(TipoBici tipo) {
	this->tipo = tipo;
}
void Bicicleta::setcantCambios(int cantCambios) {
	this->cantCambios = cantCambios;
}

		//Def
float Bicicleta::darPrecioViaje(int duracion, int distancia) {
	float precio;
	precio = this->getprecioBase() *distancia;
	return precio;
}
