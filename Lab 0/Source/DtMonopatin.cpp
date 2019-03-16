#include "../Header/DtMonopatin.h"

//Constructor
DtMonopatin::DtMonopatin() {
}
DtMonopatin::DtMonopatin (int nroSerie, float porcentaje, float precioBase,bool tieneLuces):DtVehiculo(nroSerie,porcentaje,precioBase) {
    
	this->tieneLuces=tieneLuces;
}
//Getters
bool DtMonopatin::get_tieneLuces() {
    return (this->tieneLuces);
}
