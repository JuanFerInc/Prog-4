#ifndef DTFACTURARESUMEN_H
#define DTFACTURARESUMEN_H	

#include <set>
#include "../Header/DtFactura.h"

class DtFacturaResumen {
private:
	int total;
	set<DtFactura> factura;

public:
	int getTotal();
	set<DtFactura> getFactura();
};
#endif