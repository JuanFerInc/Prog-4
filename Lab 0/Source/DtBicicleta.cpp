#include "../Header/DtBicicleta.h"

//Constructor 

DtBicicleta::DtBicicleta(int nroSerie,float porcentajeBateria,float precioBase,TipoBici tipo,int cantCambios):DtVehiculo(nroSerie,porcentajeBateria,precioBase) {
    this->tipo=tipo;
    this->cantCambios=cantCambios;
}
//Getters
TipoBici DtBicicleta::getTipoBici() const{
    return (this->tipo);
}

int DtBicicleta::getcantCambios() const {
    return (this->cantCambios);
}

