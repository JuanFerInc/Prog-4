#include "../Header/Mesa.h"



/*
s
DtFactura Mesa::facturar(int descuento){
    set<DtComidaVendida>* setsito = linkVenta->darComidas();
    int subtotal = linkVenta->getSubtotal, num = linkVenta->getNroVenta;
    string nombre = linkMozo->getNombre; 
    
    Factura* fac = new Factura(descuento, setsito, num, subtotal);
    linkVenta->finalizarVenta(fac);
    
    DtFactura retorno = fac->generarDt()
    return retorno;
}

*/

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