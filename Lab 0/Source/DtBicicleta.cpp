
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

void DtBicicleta::print(std::ostream& out) {
	using namespace std;
	out << "Numero de serie: " << this->getnroSerie() << endl;
	out << "Porcentaje de bateria: " << this->getporcentajeBateria() << endl;
	out << "Precio base: $" << this->getprecioBase() << endl;
	if (this->getTipoBici() == PASEO) {
		out << "Tipo de bicicleta: Paseo" << endl;
	}
	else {
		out << "Tipo de bicicleta: Montania" << endl;
	}
	out << "Cantidad de cambios: " << this->getcantCambios() << endl;
	
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

void DtBicicleta::print(std::ostream& out) {
	using namespace std;
	out << "Numero de serie: " << this->getnroSerie() << endl;
	out << "Porcentaje de bateria: " << this->getporcentajeBateria() << endl;
	out << "Precio base: $" << this->getprecioBase() << endl;
	if (this->getTipoBici() == PASEO) {
		out << "Tipo de bicicleta: Paseo" << endl;
	}
	else {
		out << "Tipo de bicicleta: Montania" << endl;
	}
	out << "Cantidad de cambios: " << this->getcantCambios() << endl;
	

}