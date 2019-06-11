#include "../Header/Domicilio.h"
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
	Factura(descuento, comidasParaFactura, this->nroVenta, subtotal);
}

DtDelivery Domicilio::darDtDelivery() {
	return (this->linkDelivery->darDtDelivery);
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
	DtHora hora = DtHora(minuto, hora);
	this->linkCliente->getTelefono();
	this->linkCliente->getNombre();
	this->comidaContenida;
}