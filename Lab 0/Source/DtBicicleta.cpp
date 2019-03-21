#include "../Header/DtBicicleta.h"

//Constructor 
DtBicicleta::DtBicicleta(TipoBici tipo,int cantCambios) {
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

