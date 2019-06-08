#include "../Header/DtEmpleado.h"

class DtDelivery : public DtEmpleado {
private:
	TipoTransporte transporte;
public:
	//geters
	TipoTransporte getTransporte();
	void print(std::ostream& out);
};
