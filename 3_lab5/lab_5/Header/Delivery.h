#include "../Header/Empleado.h"
#include "../Header/Domicilio.h"
#include "../Header/TipoTransporte.h"
class Delivery : public Empleado {
private:
	
	map<int, Domicilio> entregas;
	TipoTransporte tipoDeTransporte;
public:
	Delivery(string nombre, int nroEmpleado, TipoTransporte vehiculo);

	//Venta a Domicilio
	DtDelivery darDtDelivery();
};

