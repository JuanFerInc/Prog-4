#include "../Header/EnCamino.h"
#include <string>

EnCamino* EnCamino::getInstance() {
	if (instancia == NULL) {
		EnCamino* inst = new EnCamino();
		instancia = inst;
	}
	return instancia;
}

Estado* EnCamino::siguienteEstado() {
	Estado* c = Recibido::getInstance();
	return (c);
}

Estado* EnCamino::cancelarPedido() {
	Estado* c = Cancelar::getInstance();
	return (c);
}

DtEstado EnCamino::darEstadoActual() {
	string c = "EnCamino";
	DtEstado dt = DtEstado(c);
	return dt;
}