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
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	return (i->second->facturar(descuento));
}

void CtrlVenta::quitarComidaVenta(string codigo) {
	map<string, Venta*>::iterator iter;
	bool facturadas = true;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end() && facturadas; iter++) {
		if (iter->second->tieneComida(codigo)) {
			if (!iter->second->getFacturado()) {
				facturadas = false;
			}
		}
	}

	if (facturadas) {
		map<string, Venta*>::iterator iter;
		for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end(); iter++) {
			iter->second->borrarVentaProducto(codigo);
		}
	}
	else {
		throw(1);
	}
}

void CtrlVenta::quitarComidaVenta(string codigo) {
	map<string, Venta*>::iterator iter;
	bool facturadas = true;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end() && facturadas; iter++) {
		if (iter->second->tieneComida(codigo)) {
			if (!iter->second->getFacturado()) {
				facturadas = false;
			}
		}

	}


	if (facturadas) {
		map<string, Venta*>::iterator iter;
		for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end(); iter++) {
			iter->second->borrarVentaComida(codigo);
		}
	}
	else {
		throw(1);
	}
}



void CtrlVenta::quitarComidaVenta(string codigo) {
	map<string, Venta*>::iterator iter;
	bool facturadas = true;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end() && facturadas; iter++) {
		if (iter->second->tieneComida(codigo)) {
			if (!iter->second->getFacturado()) {
				facturadas = false;
			}
		}

	}


	if (facturadas) {
		map<string, Venta*>::iterator iter;
		for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end(); iter++) {
			iter->second->borrarVentaProducto(codigo);
		}
	}
	else {
		throw(1);
	}
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
	cp->getInstance();
	Comida* c = cp->pedirComida(codigo);
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	i->second->agregarComidaEnMesa(c, cantidad);

}

set<DtComida> CtrlVenta::productosEnVentaEnMesa(int nroMesa) {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	set<DtComida> c;
	c = i->second->productosEnVentaEnMesa();
	return c;
}

bool CtrlVenta::cantidadEsMayor() {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	return (i->second->cantEsMayorEnMesa(codigo, cantidad));
}

void CtrlVenta::disminuirCantidad() {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	i->second->decrementarCantidadEnMesaDeComida(codigo, cantidad);
}

void CtrlVenta::eliminarComidaDeVenta() {
	map<int, Mesa*>::iterator i;
	i = coleccionDeMesa.find(nroMesa);
	i->second->eliminarComidaDeMesa(codigo);
}

void CtrlVenta::agregarMesaAVenta(int nroMesa) {
	Mesas.insert(nroMesa);
}
set<int> CtrlVenta::mostrarMesasSeleccionadas() {
	return this->Mesas;
}
void CtrlVenta::descartarVentasEnMesa() {
	Mesas.clear();
}
set<int> CtrlVenta::mesasAsignadas(int nroEmpleado) {
	CtrlEmpleado *ce = CtrlEmpleado::getInstance(); 
	return ce->mesasDeMozo(nroEmpleado);
}
void CtrlVenta::descartarAgregado() {
	
}
void CtrlVenta::liberarnroMesa() {

}
void CtrlVenta::descartarEliminacion() {

}
DtFacturaResumen CtrlVenta::resumenDelDia(int d, int m, int a) {
	map<string, Venta*>::iterator iter;
	set<DtFactura> facturas;
	Factura* aux;
	DtFecha pepe(d, m, a);
	int total = 0;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end(); iter++) {
		if (iter->second->getFacturado()) {
			aux = iter->second->getLinkFactura();
			if (aux->getFecha() == pepe) {
				facturas.insert(aux->generarDtFactura());
				total = total + aux->getTotal();
			}
			aux = NULL;
		}
	}

}

//Venta a Domicilio

bool CtrlVenta::iniciarVentaADomicilio(string tel) {
	this->retiraEnElLocal = true;
	CtrlCliente* c = CtrlCliente::getInstance();
	bool ( c->existeCliente(tel) );
}

void CtrlVenta::seleccionarComida2(string codigo, int cantidad) {
	DtProductoMenu c = DtProductoMenu(codigo, cantidad);
	this->coleccionProductosADomicilio.insert(c);
}

set<DtDelivery> CtrlVenta::listarRepartidores() {
	CtrlEmpleado* c = CtrlEmpleado::getInstance();
	return c->darRepartidores();
}

void CtrlVenta::seleccionarRepartidor(int nroEmpleado) {
	this->retiraEnElLocal = false;
	this->nroEmpleado = nroEmpleado;
}

void CtrlVenta::cancelarVentaADomicilio() {
	this->coleccionProductosADomicilio.clear();
}

void CtrlVenta::confirmarVentaADomicilio() {
	CtrlCliente* ctrlC = CtrlCliente::getInstance();
	Cliente* cl = ctrlC->pedirCliente();
	Domicilio* dom;
	set<VentaComida*> comidaCont;
	set<DtProductoMenu>::iterator i;
	CtrlProducto* ctrlP = CtrlProducto::getInstance();
	int subtot = 0;

	for (i = coleccionProductosADomicilio.begin(); i != coleccionProductosADomicilio.end(); i++) {
		string cod = i->getCodigo();
		int cant = i->getCantidad();
		Comida* com = ctrlP->pedirComida(cod);
		VentaComida* vc = new VentaComida(com, cant);
		subtot = subtot + vc->darPrecio();
		comidaCont.insert(vc);
	}
	if (retiraEnElLocal) {
		Recibido* recibido = Recibido::getInstance();
		dom = new Domicilio(cl, recibido, to_string(nroVenta) ,comidaCont,subtot,NULL);
	}
	else {
		Pedido* pedido = Pedido::getInstance();
		CtrlEmpleado* ctrlE = CtrlEmpleado::getInstance();
		Delivery* del = ctrlE->pedirDelivery();
		dom = new Domicilio(cl, pedido, to_string(nroVenta), comidaCont, subtot, del);
	}
	Venta* res = dom;
	coleccionDeVenta.insert(make_pair(to_string(nroVenta),res));
	nroVenta = nroVenta + 1;
	coleccionProductosADomicilio.clear();
}

DtFacturaDomicilio CtrlVenta::facturarVentaADomicilio(int descuento) {
	map<string, Venta*>::iterator i;
	i = coleccionDeVenta.find(to_string(nroVenta));
	Venta* re = i->second;
	Domicilio* dom = dynamic_cast<Domicilio*> (re);
	Factura* fact = dom->crearFactura(descuento);
	DtDelivery dt = dom->darDtDelivery();
	return fact->darDtFacturaDomicilio(dt);

}