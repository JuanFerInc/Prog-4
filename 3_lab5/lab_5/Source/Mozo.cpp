#include "../Header/Mozo.h"
#include "../Header/DtMozo.h"
#include "../Header/Empleado.h"
#include "../Header/Mesa.h"
#include <map>
#include <set>



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
set<int> Mozo::getMesasLibre() {
	map<int, Mesa*>::iterator iter;
	set<int>res;

	for (iter = mesas.begin(); iter != mesas.end(); iter++) {
		if ((*iter).second->getLocal()== NULL) {
			res.insert(iter->first);
		}
		
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

