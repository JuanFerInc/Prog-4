#ifndef CLIENTE_H
#define CLIENTE_H	

#include <iostream>

#include "../Header/IObserver.h"
#include "../Header/DtDireccion.h"
#include "../Header/Domicilio.h"
#include "../Header/DtEstadoTerminado.h"


using namespace std;

class Cliente : public IObserver {
private:
	set<Domicilio*> comprasHechas;
	string telefono;
	DtDireccion direccion;
	set<DtEstadoTerminado> actualizaciones;

public:
//seters
	void setTelefono(string tel);
	void setDireccion(DtDireccion dir);
//geters
	string getTelefono();
	DtDireccion getDireccion();
	set<DtEstadoTerminado> getActualizaciones();

//Otras
	void notificar();
};
#endif