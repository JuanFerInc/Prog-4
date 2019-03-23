#include "../Header/vehiculo.h"

Vehiculo::Vehiculo() {

}
Vehiculo::Vehiculo(int nroSerie, float porcentajeBateria, float precioBase) {
	this->nroSerie = nroSerie;
	this->precioBase = precioBase;
	this->porcentajeBateria = porcentajeBateria;
}
//Get
int Vehiculo::getnroSerie() {
	return this->nroSerie;
}
float Vehiculo::getporcentajeBateria() {
	return this->porcentajeBateria;
}
float Vehiculo::getprecioBase() {
	return this->precioBase;
}
//Set
void Vehiculo::setnroSerie(int nroSerie) {
	this->nroSerie = nroSerie;
}
void Vehiculo::setporcentajeBateria(float porcentajeBateria) {
	this->porcentajeBateria = porcentajeBateria;
}
void Vehiculo::setprecioBase(float precioBase) {
	this->precioBase = precioBase;
}