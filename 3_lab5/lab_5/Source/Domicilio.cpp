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

Domicilio::Domicilio(Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery):Venta(nroVenta , comidaContenida, subtotal) {
	this->linkCliente = cliente;
	this->linkIObserver = cliente;
	this->linkEstado = estado;
	this->linkDelivery = delivery;
}

Factura* Domicilio::crearFactura(int descuento) {
	set<DtComidaVendida> comidasParaFactura;
	float subtotal = 0;
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		subtotal = subtotal + (*i)->darPrecio();
		DtComidaVendida comida = (*i)->pedirDatatypeDtComidaVendida();
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
	this->linkEstado = this->linkEstado->siguienteEstado();
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
bool Domicilio::tieneDelivery() {
	if (this->linkDelivery == NULL) {
		return false;
	}
	else {
		return true;
	}
}