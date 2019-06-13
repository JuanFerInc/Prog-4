#ifndef DTFACTURADOMICILIO_
#define DTFACTURADOMICILIO_



#include "../Header/DtFactura.h"
#include "../Header/DtDelivery.h"


class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtFacturaDomicilio(DtDelivery delivery, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida , float subtotal , float montoTotal, float montoTotalIVA, int descuento);
	DtDelivery getDelivery();

	
	void print(ostream& out);
};


#endif // !DTFACTURADOMICILIO_
