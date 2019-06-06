#include "../Header/Mesa.h"




DtFactura Mesa::facturar(int descuento) {
	set<DtComidaVendida> sc;
	sc = this->linkLocal->darComidas();
	string nv = this->linkLocal->getNroVenta();
	int st = this->linkLocal->getSubtotal();
	string nombreMozo = this->linkMozo->getNombre();
	Factura* f = new Factura(descuento, sc, nv, nombreMozo);
	DtFactura res = f->generarDtFactura();
	this->linkLocal->finalizarVenta(f);

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