#include "../Header/Delivery.h"

DtDelivery Delivery::darDtDelivery() {
	return DtDelivery(this->getNombre, this->getNroEmpleado, this->tipoDeTransporte);
}