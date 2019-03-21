#include "../Header/DtMonopatin.h"

//Constructor
DtMonopatin::DtMonopatin() {
}
DtMonopatin::DtMonopatin (int nroSerie, float porcentaje, float precioBase,bool tieneLuces):DtVehiculo(nroSerie,porcentaje,precioBase) {
    
	this->tieneLuces=tieneLuces;
}
DtMonopatin::DtMonopatin(const DtMonopatin& vehiculo) {
	
	this->tieneLuces = vehiculo.tieneLuces;
}
//Getters
bool DtMonopatin::gettieneLuces() const {
    return (this->tieneLuces);
}
float DtMonopatin::getprecioBase() const {
	return 5;
}

