#include "../Header/DtDelivery.h"

//Venta a Domicilio
DtDelivery::DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo):DtEmpleado(nombre, nroEmpleado) {
	this->transporte = tipo;
}

DtDelivery::DtDelivery(const DtDelivery& a):DtEmpleado(a.getNombre(), a.getNroEmpleado()) {
	this->transporte = a.getTransporte();

}

TipoTransporte DtDelivery::getTransporte() const {
	return this->transporte;
}