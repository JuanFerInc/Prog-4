#include "../Header/DtFactura.h"



DtFactura::DtFactura(const DtFactura &dtf) {
	this->codigo = dtf.codigo;
	this->fecha = dtf.fecha;
	this->hora = dtf.hora;
	this->comidaVendida = dtf.comidaVendida;
	this->subtotal = dtf.subtotal;
	this->montoTotal = dtf.montoTotal;
	this->montoTotalIVA = dtf.montoTotalIVA;
	this->descuento = dtf.descuento;

}
string DtFactura::getCodigo(){
	return this->codigo;
}
DtFecha DtFactura::getFecha(){
	return this->fecha;
}
DtHora DtFactura::getHora(){
}
set<DtComida> DtFactura::getComidaVendida(){
}
float DtFactura::getSubtotal(){
}
float DtFactura::getmontoTotal(){
}
float DtFactura::getSubtotalIVA(){
}
int DtFactura::getDescuento(){
}
