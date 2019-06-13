#include "../Header/CtrlEmpleado.h"
#include "../Header/TipoTransporte.h"
#include "../Header/Empleado.h"
#include "../Header/Mozo.h"
#include "../Header/Delivery.h"
#include "../Header/DtAsignacionMesa.h"
#include "../Header/Mesa.h"
#include "../Header/DtMozo.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtEmpleado.h"
#include"../Header/CtrlVenta.h"


CtrlEmpleado* CtrlEmpleado::instancia = NULL;

CtrlEmpleado::CtrlEmpleado() {
	this->setTransporte =  { BICI, MOTO, PIE };
	esMozo = false;
	tipoTransporteEmpleado = PIE;
	this->genNroEmpleados = 1;
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


set<DtAsignacionMesa> CtrlEmpleado::asignarAuto() {
	CtrlVenta *cv = CtrlVenta::getInstance();

	set<DtAsignacionMesa> res;

	int cantMesas = 0;
	int cantMozos = 0;

	map<int,Mesa*> *mesas = cv->getColeccionDeMesa();
	
	map<int, Empleado*>::iterator iterEmpleados;
	map<int, Mesa*>::iterator iterMesas;

	set<Mozo*> setMozos;

	for (iterMesas = mesas->begin(); iterMesas != mesas->end(); iterMesas++) {
		cantMesas++;
	}

	for (iterEmpleados = coleccionDeEmpleado.begin(); iterEmpleados != coleccionDeEmpleado.end(); iterEmpleados++ ) {
		Empleado *empleado = iterEmpleados->second;
		Mozo *empleadoMozo = dynamic_cast<Mozo*>(empleado);
		if (empleadoMozo != NULL) {
			setMozos.insert(empleadoMozo);
			cantMozos++;
		}
	}
	int cantAsigancion = cantMesas / cantMozos;
		
	set<Mozo*>::iterator iterMozos;
	iterMesas = mesas->begin();

	if (cantMesas < cantMozos) {
		throw(5);
	}
	else {

		//recorremos todos los mozos y agregamos la mesa correspondiente, tambien creamos el 
		//dt y agregamos al set
		//por cada mozo se agrega cantAsiganciones de mesas
		for (iterMozos = setMozos.begin(); iterMozos != setMozos.end(); iterMozos++) {
			for (int i = 0; i < cantAsigancion; i++) {
				(*iterMozos)->agregarMesa(iterMesas->first, iterMesas->second);
				iterMesas->second->asociarAMozo(*iterMozos);
				iterMesas++;
			}

		}
		iterMozos = setMozos.begin();

		//en caso que quede alguna mesa se le agrega a los mozos empesando del primero
		while (iterMesas != mesas->end()) {
			(*iterMozos)->agregarMesa(iterMesas->first, iterMesas->second);
			iterMesas->second->asociarAMozo(*iterMozos);
			iterMozos++;
			iterMesas++;
		}
	}

	DtMozo dtm;
	set<int> nroMesas;
	//recorremos todo los mozos y armarmos el resultado
	for (iterMozos = setMozos.begin(); iterMozos != setMozos.end(); iterMozos++) {
		dtm = (*iterMozos)->getDtMozo();
		nroMesas = (*iterMozos)->getMesas();
		res.insert(DtAsignacionMesa(dtm, nroMesas));
	}

	return res;
}

//Venta a Domicilio
set<DtDelivery*> CtrlEmpleado::darRepartidores() {
	map<int, Empleado*>::iterator i;
	set<DtDelivery*> res;
	for (i = coleccionDeEmpleado.begin(); i != coleccionDeEmpleado.end(); i++) {
		Empleado* c = i->second;
		Delivery* re = dynamic_cast<Delivery*> (c);
		if (re != NULL) {
			res.insert(re->darDtDelivery());
		}
	}
	return res;
}

Delivery* CtrlEmpleado::pedirDelivery() {
	map<int, Empleado*>::iterator i;
	i = coleccionDeEmpleado.find(nroEmpleado);
	Empleado* re = i->second;
	Delivery* res = dynamic_cast<Delivery*> (re);
	if (res != NULL) {
		return res;
	}
	else {
		throw (5);
	}
}
void CtrlEmpleado::seleccionarRepartidor(string nroEmpleado) {
	this->nombreEmpleado = nroEmpleado;
}