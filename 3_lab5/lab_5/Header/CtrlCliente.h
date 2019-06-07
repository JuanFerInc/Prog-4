#ifndef CTRLCLIENTE_H
#define CTRLCLIENTE_H	

#include <iostream>
#include <map>

#include "../Header/ICliente.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"
#include "../Header/DtEstadoTerminado.h"


using namespace std;

class CtrlCliente: public ICliente{
private:
	static CtrlCliente* instancia;
	map<string, Cliente*> coleccionDeClientes;

	CtrlCliente();
public:
	static CtrlCliente* getInstance();
	set<DtEstadoTerminado> verActualizacion(string tel);
	set<set<DtEstadoTerminado>> verTodasActualizaciones();

};
#endif