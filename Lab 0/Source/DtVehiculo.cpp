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
int DtVehiculo::get_nroSerie() {
    return (this->nroSerie);
}

float DtVehiculo::get_porcentaje() {
    return (this->porcentaje);
}

float DtVehiculo::get_precioBase() {
    return (this->precioBase);
}
