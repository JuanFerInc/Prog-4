#include "../Header/CtrlCliente.h"
#include <iostream>


using namespace std;


CtrlCliente* CtrlCliente::getInstance() {
	if (instancia == NULL) {
		instancia = new CtrlCliente();
	}
	return instancia;
};

set<DtEstadoTerminado> CtrlCliente::verActualizacion(string tel){
	Cliente* cliente_pepe = this->coleccionDeClientes.find(tel)->second;
	set<DtEstadoTerminado> retorno = cliente_pepe->getActualizaciones();
	return retorno;
}

set<set<DtEstadoTerminado>> CtrlCliente::verTodasActualizaciones() {
	map<string, Cliente*>::iterator iter;
	set<set<DtEstadoTerminado>> res;
	for (iter = coleccionDeClientes.begin(); iter != coleccionDeClientes.end(); iter++) {

		res.insert(	iter->second->getActualizaciones());
	}

	return res;
}


