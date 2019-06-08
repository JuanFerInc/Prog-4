#ifndef DTMOZO_H
#define DTMOZO_H
#include "../Header/DtEmpleado.h"

class DtMozo :public DtEmpleado {
public:
	void print(std::ostream& out);
};
#endif