#include "../Header/Pedido.h"
#include <string>

Pedido* Pedido::getInstance() {
	if (instancia == NULL) {
		Pedido* inst = new Pedido();
		instancia = inst;
	}
	return instancia;
}

Estado* Pedido::siguienteEstado() {
	Estado* c = EnCamino::getInstance();
	return (c);
}

Estado* Pedido::cancelarPedido() {
	Estado* c = Cancelar::getInstance();
	return (c);
}

DtEstado Pedido::darEstadoActual() {
	string c = "Pedido";
	DtEstado dt = DtEstado(c);
	return dt;
}