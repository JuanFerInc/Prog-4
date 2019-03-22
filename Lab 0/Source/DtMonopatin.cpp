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

std::ostream& operator<<(std::ostream& out, DtVehiculo* info) {
	using namespace std;

	DtMonopatin *info2 = dynamic_cast<DtMonopatin*>(info);
	out << "Numero de serie: " << info2->getnroSerie() << endl;
	out << "Porcentaje de bateria: " << info2->getporcentajeBateria() << endl;
	out << "Precio base: $" << info2->getprecioBase() << endl;
	if (info2->gettieneLuces() == 1) { cout << "Luces: si" << endl; }
	else {
		out << "Luces: no" << endl;
	}
	return out;

}
