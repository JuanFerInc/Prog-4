#ifndef DTFACTURALOCAL_H
#define DTFACTURALOCAL_H


#include "../Header/DtFactura.h"
#include "../Header/DtMozo.h"

class DtFacturaLocal : public DtFactura {
private:
	DtMozo mozo;
public:
	DtFacturaLocal(DtMozo mozo, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento);
	DtMozo getMozo();

	
	void print(ostream& out);
};


#endif // !DTFACTURALOCAL_H
