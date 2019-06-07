#include "../Header/Mozo.h"




Mozo::Mozo(string nombre, int nroEmpleado) :Empleado() {
	

}

set<int> Mozo::getMesas() {
	map<int,Mesa>::iterator iter;
	set<int>res;

	for (iter = mesas.begin(); iter != mesas.end(); iter++) {
		res.insert(iter->first);
	}

	return res;
}