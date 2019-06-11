#ifndef IOBSERVER_H
#define IOBSERVER_H	

class IObserver {
public:
	virtual void notificar(DtEstadoTerminado data) = 0;

};
#endif