#include"../Header/CtrlEmpleado.h"
#include "../Header/Mozo.h"
#include "../Header/Delivery.h"


CtrlEmpleado::CtrlEmpleado() {
	this->setTransporte =  { BICI, MOTO, PIE };
	esMozo = false;
	tipoTransporteEmpleado = PIE;
	this->genNroEmpleados = 0;
}

CtrlEmpleado* CtrlEmpleado::getInstance() {
	if (instancia == NULL) {
		instancia = new CtrlEmpleado();
	}
	return instancia;
};

set<int> CtrlEmpleado::mesasDeMozo(int nroEmpleado) {
	map<int, Empleado*>::iterator iter;
	iter = coleccionDeEmpleado.find(nroEmpleado);
	Empleado *e = iter->second;
	Mozo *pepito = dynamic_cast<Mozo*>(e);


	if (pepito != NULL) {
		return pepito->getMesas();
	}
	else {
		throw(4);
	}
}

//Alta Empleado
void CtrlEmpleado::agregarMozo(string nombre) {
	esMozo = true;
	this->nombreEmpleado = nombre;
}
set<TipoTransporte> CtrlEmpleado::agregarDelivery(string nombre) {
	this->nombreEmpleado = nombre;
	return this->setTransporte;

}
void CtrlEmpleado::elegirVehiculo(TipoTransporte vehiculo) {
	tipoTransporteEmpleado = vehiculo;
}
void CtrlEmpleado::cancelarEmpleado() {
	this->tipoTransporteEmpleado = PIE;
	this->nombreEmpleado.clear();
	if (esMozo == false) {
		tipoTransporteEmpleado = PIE;
	}
	else {
		esMozo = false;
	}
	

}
void CtrlEmpleado::confirmarEmpleado() {
	
	
	if (this->esMozo == true) {
		Mozo *m = new Mozo(this->nombreEmpleado, this->genNroEmpleados);
		coleccionDeEmpleado.insert(make_pair(genNroEmpleados, m));

	}
	else {
		Delivery *d = new Delivery(this->nombreEmpleado, this->genNroEmpleados, this->tipoTransporteEmpleado);
		coleccionDeEmpleado.insert(make_pair(this->genNroEmpleados, d));
	}
	
	this->genNroEmpleados++;
}
