#include "../Header/CtrlProducto.h"
#include "../Header/CtrlVenta.h"

set<DtComida> CtrlProducto::listaDeComidaDisponible() {
	map<string, Comida*>::iterator iter;
	set<DtComida> res;

	//puede ser ++iter
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end(); iter++) {
		res.insert(iter->second->darDataType());
	}
	return res;
}

void CtrlProducto::ingresarCodigo(string codigo) {
	this->codigo = codigo;
}
void CtrlProducto::cancelarBaja() {
	this->codigo.clear();
}

Comida* CtrlProducto::pedirComida(string codigo) {
	map<string, Comida*>::iterator i;
	i = coleccionDeComida.find(codigo);
	return i->second;
}

void CtrlProducto::confirmarBaja() {
	CtrlVenta *cv = CtrlVenta::getInstance();
	
	map<string,Comida*>::iterator iter = coleccionDeComida.find(codigo);
	
	Comida*c = iter->second;

	try {
		cv->quitarComidaVenta(iter->second->getCodigo());
		
		c->darDeBajaComida();
		coleccionDeComida.erase(iter);
		delete c;
	}
	catch(int x){
		if (x == 1) {
			cout << "existe una venta no facturada que tiene el producto que queres eliminar en quitarComidaVenta() ctrlVenta" << endl;
		}
		else {
			throw(x);
		}
	}
	
}