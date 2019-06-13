#include "../Header/CtrlCliente.h"
#include "../Header/Cliente.h"
#include "../Header/DtEstadoTerminado.h"
//#include "../Header/DtDireccion.h"				//De nuevo lo de si usar DtDireccion*
#include "../Header/DtApartamento.h"
#include "../Header/DtCliente.h"

CtrlCliente* CtrlCliente::instancia = NULL;

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

//Venta a Domicilio
bool CtrlCliente::existeCliente(string telefono) {
	this->telefono = telefono;
	map<string, Cliente*>::iterator i;
	i = coleccionDeClientes.find(telefono);
	if (i != coleccionDeClientes.end()) {
		return true;
	}
	else {
		return false;
	}
}

Cliente* CtrlCliente::pedirCliente() {
	map<string, Cliente*>::iterator i;
	i = coleccionDeClientes.find(telefono);
	return i->second;
}

Cliente* CtrlCliente::pedirCliente(string telefono) {
	map<string, Cliente*>::iterator i;
	i = coleccionDeClientes.find(telefono);
	return i->second;
}

DtCliente* CtrlCliente::agregarCliente(string telefono, string nombre, DtDireccion *dirrecion) {
	this->telefono = telefono;
	this->nombre = nombre;
	DtApartamento *ap = dynamic_cast<DtApartamento*>(dirrecion);
	if (ap != NULL) {
		this->direccion = new DtApartamento(*ap);
	}
	else {
		this->direccion = new DtDireccion(*dirrecion);
	}
	return  new DtCliente(telefono,nombre,this->direccion);
}

void CtrlCliente::cancelarCliente() {
}
void CtrlCliente::aceptarCliente() {
	Cliente *cliente = new Cliente(this->nombre, this->telefono, this->direccion);

	coleccionDeClientes.insert(make_pair(this->telefono, cliente));

}
