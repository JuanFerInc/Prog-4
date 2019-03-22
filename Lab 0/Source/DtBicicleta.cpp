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


std::ostream& operator<<(std::ostream& out, DtVehiculo* info){
	DtBicicleta *info2 = dynamic_cast<DtBicicleta*>(info);
	out << "Numero de serie: " << info2->getnroSerie() << std::endl;
	out << "Porcentaje de bateria: " << info2->getporcentajeBateria() << std::endl;
	out << "Precio base: $" << info2->getprecioBase() << std::endl;
	if (info2->getTipoBici() == PASEO) {
		out << "Tipo de bicicleta: Paseo" << std::endl;
	}
	else {
		out << "Tipo de bicicleta: montania" << std::endl;
	}
		out<< "Cantidad de cambios: " << info2->getcantCambios() << std::endl;
	return out;
}
