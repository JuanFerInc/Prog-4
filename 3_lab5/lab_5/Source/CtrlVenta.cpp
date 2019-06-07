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
	cp->getInstancie();
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

