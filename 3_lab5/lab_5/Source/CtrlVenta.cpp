#include "../Header/CtrlVenta.h"

CtrlVenta* CtrlVenta::getInstance) {
	if (instancia == NULL) {
		instancia = new CtrlVenta();
	}
	return instancia;
};


