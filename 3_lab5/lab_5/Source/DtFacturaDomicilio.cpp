#include "../Header/DtFacturaDomicilio.h"


DtDelivery DtFacturaDomicilio::getDelivery() {
	return this->delivery;
}

DtFacturaDomicilio::DtFacturaDomicilio(DtDelivery delivery, string nroFactura, DtFecha fecha, DtHora hora, set<DtComida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento):DtFactura(nroFactura,fecha,hora, comidaVendida, subtotal,montoTotal, montoTotalIVA, descuento) {
	this->delivery = delivery;
}