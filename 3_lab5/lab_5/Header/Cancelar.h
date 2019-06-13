#ifndef CANCELAR_H
#define CANCELAR_H	

#include <iostream>
#include "../Header/Estado.h"

class Cancelar : public Estado {
private:
	static Cancelar* instancia;

	Cancelar() {}
public:
	static Cancelar* getInstance();
	Estado* siguienteEstado();	
	Estado* cancelarPedido();			
	DtEstado darEstadoActual();
};
#endif