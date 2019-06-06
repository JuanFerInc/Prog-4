#ifndef ENCAMINO_H
#define ENCAMINO_H	


#include "../Header/Estado.h"
#include "../Header/Recibido.h"
#include "../Header/Cancelar.h"

class EnCamino : public Estado {
private:
	EnCamino* instancia;

	void enCamino();
public:
	EnCamino getInstance();
	Estado* siguienteEstado();
	Estado* cancelarPedido();
	DtEstado darEstadoActual();
};
#endif