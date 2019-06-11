#include "../Header/Venta.h"


Venta::Venta() {
	linkFactura = NULL;
	int subtotal = 0;
	facturado = false;
}

Venta::Venta(string nroVenta, set<VentaComida*> comidaContenida, int subtotal) {
	linkFactura = NULL;
	int subtotal = subtotal;
	facturado = false;
	this->comidaContenida = comidaContenida;
	this->nroVenta = nroVenta;
}


void Venta::borrarVentaComida(string codigo) {
	set<VentaComida*>::iterator iter;
	
	iter = comidaContenida.begin();
	bool found = false;
	VentaComida *aux = NULL;

	while ((iter != comidaContenida.end()) && (!found)) {
	
		if ( (*iter)->tieneMismo(codigo)) {
			found = true;
			aux = *iter;
			comidaContenida.erase(iter);
			delete aux;
		}
	}
}


void Venta::finalizarVenta(Factura* factura) {
	this->facturado = true;
	this->linkFactura = factura;
	set<VentaComida*>::iterator iter;



	for (iter = comidaContenida.begin(); iter != comidaContenida.end(); iter++) {
		(*iter)->incrementarCantidadUnidadesVendidas();
	}
}

//setters
void Venta::setNroVenta(string nroVenta) {
	this->nroVenta = nroVenta;
}
void Venta::setIVA(int iva) {
	Venta::IVA = iva;
}

void Venta::setSubtotal(int subtotal) {
	this->subtotoal = subtotal;
}

void Venta::setFacturado(bool facturado) {
	this->facturado = facturado;
}

//getters
string Venta::getNroVenta() {
	return this->nroVenta;
}

int Venta::getIVA() {
	return Venta::IVA;
}

int Venta::getSubtotal() {
	return this->subtotoal;
}

bool Venta::getFacturado() {
	return this->facturado;
}

set<VentaComida*> Venta::getComidaContenida() {
	return this->comidaContenida;
}

Factura* Venta::getLinkFactura() {
	return this->linkFactura;
}

void Venta::borrarVentaProducto(string codigo) {
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->ventaContieneComida(codigo)) {
			VentaComida* eliminar = (*i);
			comidaContenida.erase(i);
			delete eliminar;
		}
	}
}

bool Venta::tieneComida(string codigo) {
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->ventaContieneComida(codigo)) {
			return true;
		}
	}
	return false;
}
