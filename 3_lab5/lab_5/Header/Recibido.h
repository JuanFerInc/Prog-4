#ifndef RECIBIDO_H
#define RECIBIDO_H	


#include "../Header/Estado.h"

class Recibido : public Estado {
private:
	static Recibido* instancia;

	Recibido() {}
public:
	static Recibido* getInstance();
	Estado* siguienteEstado();	//Devuelve null (turvio sino)
	Estado* cancelarPedido();		//Devuelve null (turvio sino)
	DtEstado darEstadoActual();
};
#endif