#include "../Header/CtrlEmpleado.h"


CtrlEmpleado* CtrlEmpleado::getInstance() {
	if (instancia == NULL) {
		instancia = new CtrlEmpleado();
	}
	return instancia;
};