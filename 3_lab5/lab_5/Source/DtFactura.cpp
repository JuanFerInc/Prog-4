#include "../Header/DtFactura.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"	



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
DtFactura::DtFactura(string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento) {
	this->codigo = nroFactura;
	this->fecha = fecha;
	this->hora = hora;
	this->comidaVendida = comidaVendida;
	this->subtotal = subtotal;
	this->montoTotal = montoTotal;
	this->montoTotalIVA = montoTotalIVA;
	this->descuento = descuento;

}
string DtFactura::getCodigo(){
	return this->codigo;
}
DtFecha DtFactura::getFecha(){
	return this->fecha;
}
DtHora DtFactura::getHora(){
	return this->hora;
}
set<DtComidaVendida> DtFactura::getComidaVendida(){
	return this->comidaVendida;
}
float DtFactura::getSubtotal(){
	return this->subtotal;
}
float DtFactura::getmontoTotal(){
	return this->montoTotal;
}
float DtFactura::getSubtotalIVA(){
	return this->montoTotalIVA;
}
int DtFactura::getDescuento(){
	return this->descuento;
}

std::ostream& operator<<(std::ostream& out, DtFactura*info) {
	info->print(out);
	return out;
}

void DtFactura::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->codigo << endl;
	out << "fecha: " << &this->fecha << endl;
	out << "hora: " << &this->hora << endl;
	out << "subtotal: " << this->subtotal << endl;
	out << "monto total : " << this->montoTotal << endl;
	out << "monto total con IVA: " << this->montoTotalIVA << endl;
	out << "descuento: " << this->descuento << endl;
	set<DtComidaVendida>::iterator iter;
	out << "Las comidas son:" << endl;
	for (iter = comidaVendida.begin(); iter != comidaVendida.end(); iter++) {
		DtComidaVendida f = (*iter);
		out << " " << &f << endl;
	}
}