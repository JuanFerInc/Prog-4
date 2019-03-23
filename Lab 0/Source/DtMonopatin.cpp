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

void DtMonopatin::print(std::ostream& out) {
	using namespace std;
	out << "Numero de serie: " << this->getnroSerie() << endl;
	out << "Porcentaje de bateria: " << this->getporcentajeBateria() << endl;
	out << "Precio base: $" << this->getprecioBase() << endl;
	if (this->gettieneLuces() == 1) {
		out << "Luces: Si" << endl;
	}
	else {
		out << "Luces: No" << endl;
	}

}