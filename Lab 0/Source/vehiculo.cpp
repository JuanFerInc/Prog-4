#include "../Header/vehiculo.h"

Vehiculo::Vehiculo() {

}
Vehiculo::Vehiculo(int, float, float) {

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