#ifndef RECIBIDO_H
#define RECIBIDO_H	


#include "../Header/Estado.h"
#include "../Header/Cancelar.h"

class Recibido : public Estado {
private:
	Recibido* instancia;

	void Recibido();
public:
	Recibido getInstance();
	Estado* siguienteEstado();	//Devuelve null (turvio sino)
	Cancelar* cancelar();		//Devuelve null (turvio sino)
	DtEstado darEstadoActual();
};
#endif