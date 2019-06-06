#include "../Header/CtrlVenta.h"
#include "../Header/DtFactura.h"
#include "../Header/Factura.h"
#include "../Header/Mesa.h"



using namespace std;
CtrlVenta* CtrlVenta::getInstance() {
	if (instancia == NULL) {
		instancia = new CtrlVenta();
	}
	return instancia;
};

DtFactura CtrlVenta::generarFactura(int nromesa, int descuento){
    Mesa* mesa_del_pedido = (coleccionDeMesa.find(nromesa))->second;         //necesitamos ver bien lo de iterators
    DtFactura retorno = mesa_del_pedido->facturar(descuento);
    return retorno;
}

void CtrlVenta::ingresarNroMesa(int nroMesa) {
	this->nroMesa = nroMesa;
}

void CtrlVenta::seleccionarComida(string codigo, int cantidad) {
	this->codigo = codigo;
	this->cantidad = cantidad;
}

bool CtrlVenta::existeComidaEnVenta() {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	bool hay = i->second->hayComidaEnMesa(codigo);
	return hay;
}

void CtrlVenta::incrementarCantidad() {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	i->second->aumentarCantidadComidaEnMesa(codigo, cantidad);
}

void CtrlVenta::agregarPorPrimeraVez() {
	CtrlProducto* cp;
	cp->getInstancie();
	Comida* c = cp->pedirComida(codigo);
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	i->second->agregarComidaEnMesa(c, cantidad);

}

void CtrlVenta::descartarAgregado() {
}

void CtrlVenta::liberarnroMesa() {
}

set<DtComida> CtrlVenta::productosEnVentaEnMesa(int nroMesa) {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	set<DtComida> c;
	c = i->second->productosEnVentaEnMesa();
	return c;
}