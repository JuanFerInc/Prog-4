#ifndef DTFACTURARESUMEN_H
#define DTFACTURARESUMEN_H	

#include <set>
#include "../Header/DtFactura.h"


class DtFacturaResumen {
private:
	int total;
	set<DtFactura> factura;

public:
	DtFacturaResumen(set<DtFactura> facturas, int total);
	DtFacturaResumen(const DtFacturaResumen &dtfr);
	int getTotal();
	set<DtFactura> getFactura();
	void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, DtFacturaResumen*info);
};
#endif