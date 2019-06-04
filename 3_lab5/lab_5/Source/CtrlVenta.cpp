#include "../Header/CtrlVenta.h"

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


void CtrlVenta::quitarComidaVenta(string codigo) {
	map<string, Venta*>::iterator iter;
	bool facturadas = true;
	for (iter = coleccionDeVenta.begin(); iter != coleccionDeVenta.end() && facturadas; iter++) {
		if (iter->second->tieneComida(codigo)){
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