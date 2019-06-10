#include "../Header/DtEmpleado.h"

class DtDelivery : public DtEmpleado {
private:
	string nombre;
	TipoTransporte transporte;
public:
	DtDelivery();
	DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo);
	DtDelivery(const DtDelivery& a);
	//geters
	TipoTransporte getTransporte() const;
};
