#include "../Header/Cancelar.h"

Cancelar* Cancelar::getInstance() {
	if (instancia == NULL) {
		Cancelar* inst = new Cancelar();
		instancia = inst;
	}
	return instancia;
}

Estado* Cancelar::siguienteEstado() {
	return (instancia);
}

Estado* Cancelar::cancelarPedido() {
	return (instancia);
}

DtEstado Cancelar::darEstadoActual() {
	string c = "Cancelado";
	DtEstado dt = DtEstado(c);
	return dt;
}