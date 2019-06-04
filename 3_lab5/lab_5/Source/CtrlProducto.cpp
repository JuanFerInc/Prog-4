#include "../Header/CtrlProducto.h"


set<DtComida> CtrlProducto::listaDeComidaDisponible() {
	map<string,Comida*>::iterator iter;
	set<DtComida> res;

	//puede ser ++iter
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end();iter++) {
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
