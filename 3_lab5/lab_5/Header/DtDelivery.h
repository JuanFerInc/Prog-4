#include "../Header/DtEmpleado.h"

class DtDelivery : public DtEmpleado {
private:
	TipoTransporte transporte;
public:
	DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo);
	//geters
	TipoTransporte getTransporte();
};
