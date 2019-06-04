#include "../Header/Empleado.h"
#include "../Header/Domicilio.h"
class Delivery : public Empleado {
private:
	map<int, Domicilio> entregas;
	TipoTransporte tipoDeTransporte;
};

