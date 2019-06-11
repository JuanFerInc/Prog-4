#include "../Header/DtFacturaLocal.h"
#include "../Header/DtComidaVendida.h"

DtMozo DtFacturaLocal::getMozo() {
	return this->mozo;
}
DtFacturaLocal::DtFacturaLocal(DtMozo mozo, string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento):DtFactura(nroFactura, fecha, hora, comidaVendida,subtotal,montoTotal, montoTotalIVA,descuento) {
	this->mozo = mozo;
}
