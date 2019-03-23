
#include "../Header/DtVehiculo.h"

//Constructor
DtVehiculo::DtVehiculo() {

}
DtVehiculo::DtVehiculo(int nroSerie,float porcentaje,float precioBase) {
    this->nroSerie=nroSerie;
    this->porcentaje=porcentaje;
    this->precioBase=precioBase;
}

//Getters
int DtVehiculo::getnroSerie()const {
    return (this->nroSerie);
}

float DtVehiculo::getporcentajeBateria()const {
    return (this->porcentaje);
}

float DtVehiculo::getprecioBase()const {
    return (this->precioBase);
}

std::ostream& operator<<(std::ostream& out , DtVehiculo*info) {
	info->print(out);
	return out;

#include "../Header/DtVehiculo.h"

//Constructor
DtVehiculo::DtVehiculo() {

}
DtVehiculo::DtVehiculo(int nroSerie,float porcentaje,float precioBase) {
    this->nroSerie=nroSerie;
    this->porcentaje=porcentaje;
    this->precioBase=precioBase;
}

//Getters
int DtVehiculo::getnroSerie()const {
    return (this->nroSerie);
}

float DtVehiculo::getporcentajeBateria()const {
    return (this->porcentaje);
}

float DtVehiculo::getprecioBase()const {
    return (this->precioBase);
}

std::ostream& operator<<(std::ostream& out , DtVehiculo*info) {
	info->print(out);
	return out;

}