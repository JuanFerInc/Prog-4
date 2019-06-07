#include "../Header/Empleado.h"

class Mozo :public Empleado {
public:
	map<int,Mesa> mesas;
public:
	Mozo(string nombre, int nroEmpleado);

	set<int> getMesas();


};
