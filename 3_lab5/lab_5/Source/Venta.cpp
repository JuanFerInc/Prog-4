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
