#include "../Header/DtFacturaResumen.h"



DtFacturaResumen::DtFacturaResumen(const DtFacturaResumen &dtfr) {
	this->factura = dtfr.factura;
	this->total = dtfr.total;
}
int DtFacturaResumen::getTotal() {
	return this->total;
}
set<DtFactura> DtFacturaResumen::getFactura() {
	return this->factura;
}

std::ostream& operator<<(std::ostream& out, DtFacturaResumen*info) {
	info->print(out);
	return out;
}

void DtFacturaResumen::print(std::ostream& out) {
	using namespace std;
	out << "total: " << this->total << endl;
	out << "las facturas son:" << endl;
		set<DtFactura>::iterator iter;
	for (iter = factura.begin(); iter != factura.end(); iter++) {
		DtFactura f = (*iter);
		out << " " << &f << endl;
	}
}
