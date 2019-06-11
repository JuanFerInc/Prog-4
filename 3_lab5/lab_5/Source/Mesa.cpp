#include "../Header/Mesa.h"

DtFacturaLocal Mesa::facturar(int descuento) {
	set<DtComidaVendida> sc;
	sc = this->linkLocal->darComidas();
	string nroVenta = this->linkLocal->getNroVenta();
	int st = this->linkLocal->getSubtotal();
	string nombreMozo = this->linkMozo->getNombre();
	Factura* f = new Factura(descuento, sc, nroVenta, st);
	DtMozo dt = this->linkMozo->getDtMozo();
	DtFacturaLocal res = f->generarDtFacturaLocal(dt);
	this->linkLocal->finalizarVenta(f);

	return res;

}

bool Mesa::hayComidaEnMesa(string codigo) {
	return (this->linkLocal->hayComidaEnVenta(codigo));
}

void Mesa::aumentarCantidadComidaEnMesa(string codigo, int cantidad) {
	this->linkLocal->aumentarCantidad(codigo, cantidad);
}

void Mesa::agregarComidaEnMesa(Comida* c, int cantidad) {
	this->linkLocal->agregarComida(c, cantidad);
}

set<DtComida> Mesa::productosEnVentaEnMesa() {
	set<DtComida> c;
	c = this->linkLocal->productosEnVenta();
	return c;

}

bool Mesa::cantEsMayorEnMesa(string codigo, int cantidad) {
	return (this->linkLocal->cantEsMayor(codigo, cantidad));
}

void Mesa::decrementarCantidadEnMesaDeComida(string codigo, int cantidad) {
	this->linkLocal->decrementarCantidad(codigo, cantidad);
}

void Mesa::eliminarComidaDeMesa(string codigo) {
	this->linkLocal->eliminarComida(codigo);
}

void Mesa::asociarAMozo(Mozo*m) {
	this->linkMozo = m;
}
void Mesa::asociarALocal(Local *l) {
	this->linkLocal = l;
}

int Mesa::getNroMesa() {
	return this->nroMesa;
}
Mozo* Mesa::getMozo() {
	return this->linkMozo;
}

Local* Mesa::getLocal() {
	return this->linkLocal;
}