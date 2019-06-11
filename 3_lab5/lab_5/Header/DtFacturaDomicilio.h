#include "../Header/DtFactura.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtComidaVendida.h"

class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtFacturaDomicilio(DtDelivery delivery, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida , float subtotal , float montoTotal, float montoTotalIVA, int descuento);
	DtDelivery getDelivery();

};
