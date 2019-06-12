#ifndef MOZO_H
#define MOZO_H
#include <map>
#include <set>

#include "../Header/DtMozo.h"
#include "../Header/Empleado.h"

class Mesa;
class Mozo :public Empleado {
public:
	map<int,Mesa*> mesas;
public:
	Mozo(string nombre, int nroEmpleado);

	set<int> getMesas();
	void agregarMesa(int nroMesa, Mesa* mesa);
	DtMozo getDtMozo() const;
	


};

#include"../Header/Mesa.h"
#endif // !MOZO_H
