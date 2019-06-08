#include "../Header/DtDelivery.h"

//Venta a Domicilio
DtDelivery::DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo):DtEmpleado(nombre, nroEmpleado) {
	this->transporte = tipo;
}
