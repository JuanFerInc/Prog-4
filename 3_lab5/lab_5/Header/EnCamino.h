#ifndef ENCAMINO_H
#define ENCAMINO_H	


#include "../Header/Estado.h"
#include "../Header/Recibido.h"
#include "../Header/Cancelar.h"

class EnCamino : public Estado {
private:
	EnCamino* instancia;

	void EnCamino();
public:
	EnCamino getInstance();
	Recibido* siguienteEstado();
	Cancelar* cancelar();
	DtEstado darEstadoActual();
};
#endif