#include "../Header/CtrlVenta.h"
#include "../Header/DtFactura.h"
#include "../Header/Mesa.h"
#include "../Header/Venta.h"
#include "../Header/CtrlProducto.h"
#include "../Header/Comida.h"
#include "../Header/DtComida.h"
#include "../Header/CtrlEmpleado.h"
#include "../Header/DtFacturaResumen.h"
#include "../Header/Factura.h"
#include "../Header/DtFecha.h"
#include "../Header/CtrlCliente.h"
#include "../Header/Cliente.h"
#include "../Header/DtProductoMenu.h"
#include "../Header/DtDelivery.h"
#include "../Header/Domicilio.h"
#include "../Header/VentaComida.h"
#include "../Header/Recibido.h"
#include "../Header/Pedido.h"
#include "../Header/Delivery.h"
#include "../Header/DtFacturaDomicilio.h"
#include "../Header/Mozo.h"
#include "../Header/Local.h"

CtrlVenta* CtrlVenta::instancia = NULL;

using namespace std;
CtrlVenta::CtrlVenta() {
	genNroVenta = 0;
}
CtrlVenta* CtrlVenta::getInstance() {
	if (instancia == NULL) {
		instancia = new CtrlVenta();
	}
	return instancia;
};

DtFactura* CtrlVenta::generarFactura(int nromesa, int descuento){
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
	CtrlProducto* cp = CtrlProducto::getInstance();
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
	set<DtFactura*> facturas;
	Factura* aux = NULL;;
	DtFecha pepe(d, m, a);
	float total = 0;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end(); iter++) {
		if (iter->second->getFacturado()) {

			if (aux->getFecha() == pepe) {
						
				aux = iter->second->getLinkFactura();
				Local *l = dynamic_cast<Local*>(iter->second);
				Domicilio *d = dynamic_cast<Domicilio*>(iter->second);
				
				if (l != NULL) {
					DtMozo  m = l->getDtMozo();
					facturas.insert(aux->generarDtFacturaLocal(m));
				
				}
				else {
					if (d->tieneDelivery()) {
						DtDelivery *c = d->darDtDelivery();
						facturas.insert(aux->darDtFacturaDomicilio(*c));
						delete c;
					}
					else {
						facturas.insert(aux->darDtFacturaDomicilioSinDelivery());
					}
				}				
				total = (total + aux->getMontoTotal());
			}
			aux = NULL;
		}
	}
	 DtFacturaResumen resumen(facturas, (int)total);
	 return resumen;
}

//Venta a Domicilio

bool CtrlVenta::iniciarVentaADomicilio(string tel) {
	this->retiraEnElLocal = true;
	CtrlCliente* c = CtrlCliente::getInstance();
	return ( c->existeCliente(tel) );


}

void CtrlVenta::seleccionarComida2(string codigo, int cantidad) {
	DtProductoMenu c = DtProductoMenu(codigo, cantidad);
	this->coleccionProductosADomicilio.insert(c);
}

set<DtDelivery*> CtrlVenta::listarRepartidores() {
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
		dom = new Domicilio(cl, recibido, to_string(genNroVenta) ,comidaCont,subtot,NULL);
	}
	else {
		Pedido* pedido = Pedido::getInstance();
		CtrlEmpleado* ctrlE = CtrlEmpleado::getInstance();
		Delivery* del = ctrlE->pedirDelivery();
		dom = new Domicilio(cl, pedido, to_string(genNroVenta), comidaCont, subtot, del);
	}
	Venta* res = dom;
	coleccionDeVenta.insert(make_pair(to_string(genNroVenta),res));
	nroVenta = genNroVenta;//
	genNroVenta = genNroVenta + 1;
	
	coleccionProductosADomicilio.clear();
}

//Si retiraEnLocal == true invoca facturarVentaADomicilioSinDelivery()
//sino invoca facturarVentaADomicilio()
DtFacturaDomicilio CtrlVenta::facturarVentaADomicilio(int descuento) {
	map<string, Venta*>::iterator i;
	i = coleccionDeVenta.find(to_string(nroVenta-1));
	Venta* re = i->second;
	Domicilio* dom = dynamic_cast<Domicilio*> (re);
	Factura* fact = dom->crearFactura(descuento);
	DtDelivery *dt = dom->darDtDelivery();
	DtFacturaDomicilio *res = fact->darDtFacturaDomicilio(*dt);
	delete dt;
	return *res;
}

DtFactura CtrlVenta::facturarVentaADomicilioSinDelivery(int descuento) {
	map<string, Venta*>::iterator i;
	i = coleccionDeVenta.find(to_string(nroVenta));
	Venta* re = i->second;
	Domicilio* dom = dynamic_cast<Domicilio*> (re);
	Factura* fact = dom->crearFactura(descuento);
	return *fact->darDtFacturaDomicilioSinDelivery();

}

void CtrlVenta::confirmarVentaEnMesas() {
	set<int>::iterator iterNroMesa;
	map<int, Mesa*>mesasParaAsociar;
	map<int, Mesa*>::iterator iterMesa;

	for (iterNroMesa = Mesas.begin(); iterNroMesa != Mesas.end(); iterNroMesa++) {
		iterMesa = coleccionDeMesa.find(*iterNroMesa);
		mesasParaAsociar.insert(make_pair(iterMesa->first, iterMesa->second));
	}

	iterMesa = coleccionDeMesa.begin();

	Mozo *m = iterMesa->second->getMozo();
	Venta *v = new Local(mesasParaAsociar,to_string(genNroVenta),m);
	genNroVenta++;

	coleccionDeVenta.insert(make_pair(v->getNroVenta(),v));
}

//obtengo venta
//si es venta local tiro error
//sino cancelo venta de domicilio
void CtrlVenta::cancelarPedido(int nroVenta) {
	map<string, Venta*>::iterator iter;

	iter = coleccionDeVenta.find(to_string(nroVenta));
	
	Domicilio*c = dynamic_cast<Domicilio*>(iter->second);
	if (c != NULL) {
		c->cancelarPedido();
	}
	else {
		throw(6);
	}

}



map<int, Mesa*> *CtrlVenta::getColeccionDeMesa() {
	map<int, Mesa*> *res = NULL;
	*res = coleccionDeMesa;
	return res;
}

void CtrlVenta::siguienteEstado(int nroVenta) {
	map<string, Venta*>::iterator iter;

	iter = coleccionDeVenta.find(to_string(nroVenta));

	Domicilio*c = dynamic_cast<Domicilio*>(iter->second);
	if (c != NULL) {
		c->siguienteEstado();
	}
	else {
		throw(6);
	}
}