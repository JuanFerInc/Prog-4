#include "../Header/DtBicicleta.h"

//Constructor 
DtBicicleta(TipoBici tipo,int cantCambios) {
    this->tipo=tipo;
    this->cantCambios=cantCambios;
}
//Getters
TipoBici get_TipoBici() {
    return (this->TipoBici);
}

int get_cantCambios() {
    return (this->cantCambios);
}
//Destructor
