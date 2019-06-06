#ifndef DTFACTURARESUMEN_H
#define DTFACTURARESUMEN_H	

#include <set>
#include "../Header/DtFactura.h"

class DtFacturaResumen {
private:
	int total;
	set<DtFactura> factura;

public:
	DtFacturaResumen(const DtFacturaResumen &dtfr);
	int getTotal();
	set<DtFactura> getFactura();
};
#endif