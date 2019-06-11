#ifndef CLIENTE_H
#define CLIENTE_H	

#include <iostream>

#include "../Header/IObserver.h"
#include "../Header/DtDireccion.h"

#include "../Header/DtEstadoTerminado.h"


using namespace std;
class Domicilio;
class Cliente : public IObserver {
private:
	string nombre;
	string telefono;
	DtDireccion direccion;

	set<Domicilio*> comprasHechas;
	set<DtEstadoTerminado> actualizaciones;

public:
	Cliente(string nombre,string telefono, DtDireccion direccion);

//seters
	void setTelefono(string tel);
	void setDireccion(DtDireccion dir);
//geters
	string getNombre();
	string getTelefono();
	DtDireccion getDireccion();
	set<DtEstadoTerminado> getActualizaciones();

//Otras
	void notificar(DtEstadoTerminado data);
};
#include "../Header/Domicilio.h"
#endif