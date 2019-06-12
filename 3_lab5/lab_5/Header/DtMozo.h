#ifndef DTMOZO_H
#define DTMOZO_H


#include "../Header/DtEmpleado.h"

class DtMozo :public DtEmpleado {
private:

public:
	DtMozo();
	DtMozo(int nroEmpleado,string nombre );
	DtMozo(const DtMozo & dtmozo);

	
	void print(ostream& out);
};


#endif // !DTMOZO_H
