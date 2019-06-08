#ifndef CTRLEMPLEADO_H
#define CTRLEMPLEADO_H	

#include <iostream>
#include <map>
#include <set>

#include "../Header/Empleado.h"
#include "../Header/IEmpleado.h"
#include "../Header/TipoTransporte.h"
#include  "../Header/DtAsignacionMesa.h"


using namespace std;

class CtrlEmpleado: public IEmpleado {
private:
	static CtrlEmpleado* instancia;

	map<int, Empleado*> coleccionDeEmpleado;
	
	string nombreEmpleado;
	int genNroEmpleados;
	bool esMozo;
	TipoTransporte tipoTransporteEmpleado;
	set<TipoTransporte> setTransporte;



	CtrlEmpleado();
public:
	static CtrlEmpleado* getInstance();
	set<int> mesasDeMozo(int nroEmpleado);


	//Alta Empleado
	void agregarMozo(string nombre);
	set<TipoTransporte> agregarDelivery(string nombre);
	void elegirVehiculo(TipoTransporte vehiculo);
	void cancelarEmpleado();
	void confirmarEmpleado();

	set<DtAsignacionMesa> asignarAuto();

};
#endif