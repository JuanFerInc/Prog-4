#ifndef CANCELAR_H
#define CANCELAR_H	


#include "../Header/Estado.h"

class Cancelar : public Estado {
private:
	static Cancelar* instancia;

	Cancelar();
public:
	static Cancelar* getInstance();
	Estado* siguienteEstado();	//Devuelve null (turvio sino)
	Estado* cancelarPedido();			//Devuelve null (turvio sino)
	DtEstado darEstadoActual();
};
#endif