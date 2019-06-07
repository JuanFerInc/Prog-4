#ifndef IEMPLEADOS
#define IEMPLEADOS_H

#include <iostream>
#include <set>

using namespace std;

class IEmpleado {
public:
	virtual set<int> mesasDeMozo(int nroEmpleado) = 0;
	virtual void elegirVehiculo(TipoTransporte vehiculo)=0;
	virtual void cancelarEmpleado()=0;
	virtual void confirmarEmpleado()=0;
	virtual void agregarMozo(string nombre)=0;
	virtual set<TipoTransporte> agregarDelivery(string nombre)=0;

};

#endif


