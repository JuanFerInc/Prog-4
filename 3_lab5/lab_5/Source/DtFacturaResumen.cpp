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