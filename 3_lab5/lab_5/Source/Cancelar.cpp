#include "../Header/Cancelar.h"
#include"../Header/Estado.h"
#include"../Header/DtEstado.h"


Cancelar* Cancelar::instancia = NULL;


Cancelar* Cancelar::getInstance() {
	if (instancia == NULL) {
		instancia = new Cancelar();
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