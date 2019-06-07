#ifndef ENCAMINO_H
#define ENCAMINO_H	


#include "../Header/Estado.h"
#include "../Header/Recibido.h"
#include "../Header/Cancelar.h"

class EnCamino : public Estado {
private:
	static EnCamino* instancia;

	EnCamino();
public:
	static EnCamino* getInstance();
	Estado* siguienteEstado();
	Estado* cancelarPedido();
	DtEstado darEstadoActual();
};
#endif