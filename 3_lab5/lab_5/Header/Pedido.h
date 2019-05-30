#ifndef PEDIDO_H
#define PEDIDO_H	


#include "../Header/Estado.h"
#include "../Header/EnCamino.h"
#include "../Header/Cancelar.h"

class Pedido: public Estado{
private: 
	Pedido* instancia;

	void Pedido();
public:
	Pedido getInstance();
	EnCamino* siguienteEstado();
	Cancelar* cancelar();
	DtEstado darEstadoActual();
};
#endif