#include "../Header/DtEmpleado.h"

class DtMozo :public DtEmpleado {
private:

public:
	DtMozo();
	DtMozo(int nroEmpleado,string nombre );
	DtMozo(const DtMozo & dtmozo);


};
