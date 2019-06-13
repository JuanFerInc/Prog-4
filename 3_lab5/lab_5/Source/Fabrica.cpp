#include "../Header/Fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstance() {
	if (instancia == NULL) {
		instancia = new Fabrica();
	}
	return instancia;
}
IVenta* Fabrica::getIVenta() {
	return CtrlVenta::getInstance();
}
IProducto* Fabrica::getIProducto() {
	return CtrlProducto::getInstance();
}
IEmpleado* Fabrica::getIEmpleado() {
	return CtrlEmpleado::getInstance();
}
ICliente* Fabrica::getICliente() {
	return CtrlCliente::getInstance();
}