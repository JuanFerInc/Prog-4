#ifndef DTESTADO_H
#define DTESTADO_H

#include <iostream>
#include <set>
#include "../Header/DtComidaVendida.h"
#include "../Header/DtHora.h"
#include "../Header/Estado.h"

using namespace std;


class DtEstado {
private:
	Estado* etapaActual;

public:
	string getEtapaActual();
};

class DtEstadoTerminado : public DtEstado {
private:
	string nombre, telefono;
	DtHora hora;
	set<DtComidaVendida> comidasVendidas;

public:
	string getNombre();
	string getTelefono();
	DtHora getHora();
	set<DtComidaVendida> getComidasVendidas();


};
#endif