#ifndef IOBSERVER_H
#define IOBSERVER_H	

#include "../Header/DtEstadoTerminado.h"


class IObserver {
public:
	virtual void notificar(DtEstadoTerminado data) = 0;

};
#endif