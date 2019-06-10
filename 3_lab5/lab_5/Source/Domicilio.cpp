#include "../Header/Domicilio.h"

Domicilio::Domicilio(Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery):Venta(nroVenta , comidaContenida, subtotal) {
	this->linkCliente = cliente;
	this->linkIObserver = cliente;
	this->linkEstado = estado;
	this->linkDelivery = delivery;
}

Factura* Domicilio::crearFactura(int descuento) {
	int descuento
	DtComidaVendida comidaEnFactura;
	string nroFactura;
	int subtotal
}

DtDelivery Domicilio::darDtDelivery() {
	return (this->linkDelivery->darDtDelivery);
}