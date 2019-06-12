#include "../Header/Recibido.h"
#include <string>
#include "../Header/Estado.h"
#include "../Header/DtEstado.h"

Recibido* Recibido::instancia = NULL;

Recibido* Recibido::getInstance() {
	if (instancia == NULL) {
		instancia = new Recibido();
		
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