#define _CRT_SECURE_NO_WARNINGS
#include "../Header/Factura.h"
#include <ctime>
#include "../Header/DtComidaVendida.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtFacturaLocal.h"				//No me cierran estos dos includes
#include "../Header/DtFacturaDomicilio.h"
#include "../Header/DtFactura.h"
#include "../Header/DtDelivery.h"
#include "../Header/Venta.h"
#include "../Header/DtMozo.h"

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

DtFacturaDomicilio *Factura::darDtFacturaDomicilio(DtDelivery dt) {
	float desc = 1 - ((float)descuento / (float)100);
	float montoTotal = this->subtotal* desc;
	float montoTotalIVA = montoTotal + (montoTotal * ((float)Venta::getIVA()/100));
	return new DtFacturaDomicilio(dt, this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, montoTotal ,montoTotalIVA , this->descuento);
}

DtFactura *Factura::darDtFacturaDomicilioSinDelivery() {
	float desc = 1 - ((float)descuento / (float)100);
	float montoTotal = this->subtotal* desc;
	float montoTotalIVA = (montoTotal + (montoTotal * ((float)Venta::getIVA()/100)));
	return new DtFactura(this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, montoTotal, montoTotalIVA, this->descuento);
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

DtFacturaLocal *Factura::generarDtFacturaLocal(DtMozo dt) {
	float montoTotalIVA = this->getMontoTotal() + (this->getMontoTotal() * (Venta::getIVA() / 100));
	return (new DtFacturaLocal(dt,this->nroFactura, this->fecha, this->hora, this->comidaEnFactura, this->subtotal, this->getMontoTotal(), montoTotalIVA, this->descuento));

}