#include "../Header/Local.h"

bool Local::hayComidaEnVenta(string codigo) {
	set<VentaComida*>::iterator i;
	bool hay = false;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		if ((*i)->ventaContieneComida(codigo)) {
			hay = true;
		}
	}
	return hay;
}

void Local::aumentarCantidad(string codigo, int cantidad) {
	set<VentaComida*>::iterator i;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		(*i)->incrementarCantidad(codigo, cantidad);
	}
}

void Local::agregarComida(Comida* c, int cantidad) {
	VentaComida* res = new VentaComida(c, cantidad);
	comidaContenida.insert(res);
}
//REVISAR LOS PUNTEROS
set<DtComida> Local::productosEnVenta() {
	set<VentaComida*>::iterator i;
	set<DtComida*> res;
	for (i = comidaContenida.begin(); i != comidaContenida.end(); i++) {
		DtComida* re = (*i)->pedirDatatypeAComida();
		res.insert(re);

	}
}