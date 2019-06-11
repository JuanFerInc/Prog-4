#include "../Header/Delivery.h"

DtDelivery Delivery::darDtDelivery() {
	return DtDelivery(this->getNombre, this->getNroEmpleado, this->tipoDeTransporte);
}

Delivery::Delivery(string nombre, int nroEmpleado, TipoTransporte vehiculo):Empleado(nombre, nroEmpleado) {
	this->tipoDeTransporte = vehiculo;
}