#include "../Header/DtFacturaLocal.h"			//Hay que ver de cambiar todos los atributos privados a protected
#include "../Header/DtFactura.h"
#include "../Header/DtMozo.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"


DtMozo DtFacturaLocal::getMozo() {
	return this->mozo;
}
DtFacturaLocal::DtFacturaLocal(DtMozo mozo, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento):DtFactura(nroFactura, fecha, hora, comidaVendida,subtotal,montoTotal, montoTotalIVA,descuento) {
	this->mozo = mozo;
}


void DtFacturaLocal::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->getCodigo() << endl;
	out << "fecha: " << endl << &this->fecha << endl;
	out << &this->hora << endl;

	set<DtComidaVendida>::iterator iter;
	out << "Las comidas son:" << endl;
	for (iter = comidaVendida.begin(); iter != comidaVendida.end(); iter++) {
		DtComidaVendida f = (*iter);
		out << "" << &f << endl;
	}
	out << "subtotal: " << this->getSubtotal() << endl;
	out << "descuento: " << this->getDescuento() << endl;
	out << "monto total : " << this->getmontoTotal() << endl;
	out << "monto total con IVA: " << this->getSubtotalIVA() << endl;
	out << "mozo: " << &this->mozo << endl;
}