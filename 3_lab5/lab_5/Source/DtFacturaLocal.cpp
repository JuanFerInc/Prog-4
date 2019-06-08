#include "../Header/DtFacturaLocal.h"

DtMozo DtFacturaLocal::getMozo() {
	return this->mozo;
}

void DtFacturaLocal::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->getCodigo << endl;
	out << "fecha: " << &this->getFecha << endl;
	out << "hora: " << &this->getHora << endl;
	out << "subtotal: " << this->getSubtotal << endl;
	out << "monto total : " << this->getmontoTotal << endl;
	out << "monto total con IVA: " << this->getSubtotalIVA << endl;
	out << "descuento: " << this->getDescuento << endl;
	set<DtComida>::iterator iter;
	out << "Las comidas son:" << endl;
	for (iter = getComidaVendida().begin(); iter != getComidaVendida().end(); iter++) {
		DtComida f = (*iter);
		out << " " << &f << endl;
	}
	out << "mozo: " << &this->mozo << endl;
}