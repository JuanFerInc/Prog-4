#include "../Header/Fabrica.h"
#include <ctime>

Factura::Factura(int descuento, set<DtComidaVendida> comidaEnFactura, string nroFactura, float subtotal) {
	this->descuento = descuento;
	this->comidaEnFactura = comidaEnFactura;
	this->nroFactura = nroFactura;
	this->subtotal = subtotal;
	//Obtenemos el tiempo de la computardora
		// se le suma 1 al mes
		// se le suma 1900 al anio
	time_t current_time = time(0);
	tm *t = localtime(&current_time);

	int dia = t->tm_mday;
	int mes = t->tm_mon + 1;
	int anio = t->tm_year + 1900;
	int hora = t->tm_hour;
	int minuto = t->tm_min;
	this->fecha = DtFecha(dia, mes, anio);
	this->hora = DtHora(minuto, hora);
}

DtFacturaDomicilio Factura::darDtFacturaDomicilio(DtDelivery dt) {
	float montoTotal = this->subtotal* (1 -(descuento / 100));
	float montoTotalIVA = montoTotal + (montoTotal * Venta::getIVA());
	return DtFacturaDomicilio(dt, this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, montoTotal ,montoTotalIVA , this->descuento);
}

DtFactura Factura::darDtFacturaDomicilioSinDelivery() {
	float montoTotal = this->subtotal* (1 - (descuento / 100));
	float montoTotalIVA = montoTotal + (montoTotal * Venta::getIVA());
	return DtFactura(this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, montoTotal, montoTotalIVA, this->descuento);
}

DtFecha Factura::getFecha() {
	return this->fecha;
}
DtHora Factura::getHora() {
	return this->hora;
}
int Factura::getDescuento() {
	return this->descuento;
}
set<DtComidaVendida> Factura::getComidaEnFactura() {
	return this->comidaEnFactura;
}
string Factura::getNroFactura() {
	return this->nroFactura;
}
float Factura::getSubtotal() {
	return this->subtotal;
}
float Factura::getMontoTotal() {
	return this->subtotal* (1 - (descuento / 100));
}

DtFactura Factura::generarDtFactura() {
	float montoTotalIVA = this->getMontoTotal() + (this->getMontoTotal() * (Venta::getIVA() / 100));
	return DtFactura(this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, this->getMontoTotal(), montoTotalIVA, this->descuento);

}