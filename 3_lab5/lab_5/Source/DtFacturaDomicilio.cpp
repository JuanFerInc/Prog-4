#include "../Header/DtFacturaDomicilio.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFactura.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"		//Tengo que mirar mejor lo de tener un set de dtcomida
#include "../Header/DtComida.h"				//Raro lo de los getters comparadoos con iter
#include "../Header/TipoTransporte.h"


DtDelivery DtFacturaDomicilio::getDelivery() {
	return this->delivery;
}

DtFacturaDomicilio::DtFacturaDomicilio(DtDelivery delivery, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento):DtFactura(nroFactura,fecha,hora, comidaVendida, subtotal,montoTotal, montoTotalIVA, descuento) {
	this->delivery = delivery;
}

void DtFacturaDomicilio::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->getCodigo() << endl;
	out << "fecha: " << endl << &this->fecha << endl;
	out << &this->hora << endl;
	set<DtComidaVendida>::iterator iter;
	out << "Las comidas son: " << endl;
	for (iter = this->comidaVendida.begin(); iter != this->comidaVendida.end(); iter++) {
		DtComidaVendida f = (*iter);
		out << "" << &f << endl;
	}
	out << "subtotal: " << this->getSubtotal() << endl;
	out << "descuento: " << this->getDescuento() << endl;
	out << "monto total : " << this->getmontoTotal() << endl;
	out << "monto total con IVA: " << this->getSubtotalIVA() << endl;

	out << "delivery: " << endl << &this->delivery << endl;

}

