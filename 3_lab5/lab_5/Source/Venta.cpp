#include "../Header/Venta.h"

void Venta::borrarVentaProducto(string codigo) {
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

