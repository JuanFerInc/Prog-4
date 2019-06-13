#include "../Header/DtFacturaDomicilio.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFactura.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"		//Tengo que mirar mejor lo de tener un set de dtcomida
#include "../Header/DtComida.h"				//Raro lo de los getters comparadoos con iter



DtDelivery DtFacturaDomicilio::getDelivery() {
	return this->delivery;
}

DtFacturaDomicilio::DtFacturaDomicilio(DtDelivery delivery, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento):DtFactura(nroFactura,fecha,hora, comidaVendida, subtotal,montoTotal, montoTotalIVA, descuento) {
	this->delivery = delivery;
}

void DtFacturaDomicilio::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->getCodigo() << endl;
	out << "fecha: " << &this->fecha << endl;
	out << "hora: " << &this->hora << endl;
	out << "subtotal: " << this->getSubtotal() << endl;
	out << "monto total : " << this->getmontoTotal()<< endl;
	out << "monto total con IVA: " << this->getSubtotalIVA() << endl;
	out << "descuento: " << this->getDescuento() << endl;
	set<DtComidaVendida>::iterator iter;
	out << "Las comidas son:" << endl;
	for (iter = getComidaVendida().begin(); iter != getComidaVendida().end(); iter++) {
		DtComidaVendida f = (*iter);
		out << " " << &f << endl;
	}
	out << "delivery: " << &this->delivery << endl;
}
