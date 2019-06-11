#include "../Header/Mozo.h"




Mozo::Mozo(string nombre, int nroEmpleado) :Empleado(nombre,nroEmpleado) {
}

set<int> Mozo::getMesas() {
	map<int,Mesa*>::iterator iter;
	set<int>res;

	for (iter = mesas.begin(); iter != mesas.end(); iter++) {
		res.insert(iter->first);
	}

	return res;
}
void Mozo::agregarMesa(int nroMesa, Mesa* mesa) {
	mesas.insert(make_pair(nroMesa, mesa));

}

DtMozo Mozo::getDtMozo() const {
	DtMozo res(this->getNroEmpleado(), this->getNombre());
	return res;
}
set<int> Mozo::getMesasDelMozo() const {
	set<int> res;
	map<int, Mesa*>::iterator iter;

	for (iter = mesas.begin(); iter != mesas.end(); iter++) {
		res.insert(iter->first);
	}
	return res;
}