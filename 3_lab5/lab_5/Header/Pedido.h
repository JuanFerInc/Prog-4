#ifndef PEDIDO_H
#define PEDIDO_H	


#include "../Header/Estado.h"
#include "../Header/EnCamino.h"
#include "../Header/Cancelar.h"

class Pedido: public Estado{
private: 
	Pedido* instancia;

	void pedido();
public:
	Pedido getInstance();
	Estado* siguienteEstado();
	Estado* cancelarPedido();
	DtEstado darEstadoActual();
};
#endif