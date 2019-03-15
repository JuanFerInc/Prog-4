
#include "../Header/DtVehiculo.h"

//Constructor
DtVehiculo(int nroSerie,float porcentaje,float precioBase) {
    this->nroSerie=nroSerie;
    this->porcentaje=porcentaje;
    this->precioBase=precioBase;
}
//Getters
int get_nroSerie() {
    return (this->nroSerie);
}

float get_porcentaje() {
    return (this->porcentaje);
}

float get_precioBase() {
    return (this->precioBase);
}
//Destructor
