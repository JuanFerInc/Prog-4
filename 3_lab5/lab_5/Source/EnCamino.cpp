#include "../Header/EnCamino.h"
#include "../Header/Estado.h"
#include "../Header/Cancelar.h"
#include "../Header/Recibido.h"
#include "../Header/DtEstado.h"
#include <string>

EnCamino* EnCamino::instancia = NULL;

EnCamino* EnCamino::getInstance() {
	if (instancia == NULL) {
		instancia = new EnCamino();
		
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