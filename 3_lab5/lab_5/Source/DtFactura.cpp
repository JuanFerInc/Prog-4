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
	set<DtComida>::iterator iter;
	out << "Las comidas son:" << endl;
	for (iter = comidaVendida.begin(); iter != comidaVendida.end(); iter++) {
		DtComida f = (*iter);
		out << " " << &f << endl;
	}
}
