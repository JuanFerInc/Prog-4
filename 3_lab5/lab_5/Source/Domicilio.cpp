#define _CRT_SECURE_NO_WARNINGS
#include "../Header/Domicilio.h"
#include "../Header/Factura.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"
#include "../Header/VentaComida.h"
#include "../Header/Delivery.h"
#include "../Header/Venta.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/DtEstado.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtEstadoTerminado.h"
#include "../Header/DtHora.h"
#include <ctime>

Domicilio::Domicilio(Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery) :Venta(nroVenta, comidaContenida, subtotal) {
	this->linkCliente = cliente;
	this->linkIObserver = cliente;
	this->linkEstado = estado;
	this->linkDelivery = delivery;
	DtEstado p = this->linkEstado->darEstadoActual();
	DtEstadoTerminado dtEstadoTerminado = this->darDatatypeTerminado(p);
	this->linkIObserver->notificar(dtEstadoTerminado);
}
Domicilio::Domicilio(DtHora horita, Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery) :Venta(nroVenta, comidaContenida, subtotal) {
	this->linkCliente = cliente;
	this->linkIObserver = cliente;
	this->linkEstado = estado;
	this->linkDelivery = delivery;
	DtEstado p = this->linkEstado->darEstadoActual();
	DtEstadoTerminado dtEstadoTerminado = this->darDatatypeTerminado(p, horita);
	this->linkIObserver->notificar(dtEstadoTerminado);
}

Factura* Domicilio::crearFactura(int descuento) {
	set<DtComidaVendida> comidasParaFactura;
	float subtotal = 0;
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		subtotal = subtotal + (*i)->darPrecio();
		DtComidaVendida comida = (*i)->pedirDatatypeDtComidaVendida();
		//(*i)->incrementarCantidadUnidadesVendidas();
		comidasParaFactura.insert(comida);

	}
	return new Factura(descuento, comidasParaFactura, this->nroVenta, subtotal);

}

DtDelivery* Domicilio::darDtDelivery() {
	return (this->linkDelivery->darDtDelivery());
}

void Domicilio::cancelarPedido() {
	this->linkEstado = this->linkEstado->cancelarPedido();
}


void Domicilio::siguienteEstado() {
	Estado* res = this->linkEstado->siguienteEstado();
	if (res != this->linkEstado) {
		DtEstado p = res->darEstadoActual();
		DtEstadoTerminado dtEstadoTerminado = this->darDatatypeTerminado(p);
		linkIObserver->notificar(dtEstadoTerminado);
		this->linkEstado = res;
	}
}
void Domicilio::siguienteEstado(DtHora horita) {
	Estado* res = this->linkEstado->siguienteEstado();
	if (res != this->linkEstado) {
		DtEstado p = res->darEstadoActual();
		DtEstadoTerminado dtEstadoTerminado = this->darDatatypeTerminado(p, horita);
		linkIObserver->notificar(dtEstadoTerminado);
		this->linkEstado = res;
	}
}
DtEstadoTerminado Domicilio::darDatatypeTerminado(DtEstado estado) {
	time_t current_time = time(0);
	tm *t = localtime(&current_time);
	int hora = t->tm_hour;
	int minuto = t->tm_min;
	DtHora horas(minuto, hora);
	
	set<VentaComida*>::iterator iter;
	set<DtComidaVendida*>comidas;


	for (iter = comidaContenida.begin(); iter != comidaContenida.end(); iter++) {
		VentaComida *vc = *iter;
		comidas.insert(vc->darDtComidayCantidad());
	}


	return DtEstadoTerminado(this->linkCliente->getNombre(), this->linkCliente->getTelefono(), horas, estado.getEtapaActual(), comidas);
}
DtEstadoTerminado Domicilio::darDatatypeTerminado(DtEstado estado, DtHora horita) {
	set<VentaComida*>::iterator iter;
	set<DtComidaVendida*>comidas;


	for (iter = comidaContenida.begin(); iter != comidaContenida.end(); iter++) {
		VentaComida *vc = *iter;
		comidas.insert(vc->darDtComidayCantidad());
	}


	return DtEstadoTerminado(this->linkCliente->getNombre(), this->linkCliente->getTelefono(), horita, estado.getEtapaActual(), comidas);
}
bool Domicilio::tieneDelivery() {
	if (this->linkDelivery == NULL) {
		return false;
	}
	else {
		return true;
	}
}