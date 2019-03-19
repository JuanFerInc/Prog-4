#include "../Header/DtBicicleta.h"

//Constructor 
DtBicicleta::DtBicicleta(TipoBici tipo,int cantCambios) {
    this->tipo=tipo;
    this->cantCambios=cantCambios;
}
//Getters
TipoBici DtBicicleta::get_TipoBici() {
    return (this->tipo);
}

int DtBicicleta::get_cantCambios() {
    return (this->cantCambios);
}
