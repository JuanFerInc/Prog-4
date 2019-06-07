#include "../Header/Recibido.h"
#include <string>

Recibido* Recibido::getInstance() {
	if (instancia == NULL) {
		Recibido* inst = new Recibido();
		instancia = inst;
	}
	return instancia;
}

Estado* Recibido::siguienteEstado() {
	return instancia;
}

Estado* Recibido::cancelarPedido() {
	return instancia;
}

DtEstado Recibido::darEstadoActual() {
	string c = "Recibido";
	DtEstado dt = DtEstado(c);
	return dt;
}