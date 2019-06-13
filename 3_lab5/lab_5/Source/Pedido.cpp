#include "../Header/Pedido.h"
#include <string>
#include "../Header/Estado.h"
#include "../Header/EnCamino.h"
#include "../Header/DtEstado.h"
#include "../Header/Cancelar.h"

Pedido* Pedido::instancia = NULL;

Pedido* Pedido::getInstance() {
	if (instancia == NULL) {
		instancia = new Pedido();
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