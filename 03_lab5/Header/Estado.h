#ifndef ESTADO_H
#define ESTADO_H	

#include <iostream>
#include "../Header/DtEstado.h"

using namespace std;

class Estado {
public:
	virtual Estado* siguienteEstado() = 0;
	virtual Estado* cancelarPedido() = 0;
	virtual DtEstado darEstadoActual() = 0;
};
#endif