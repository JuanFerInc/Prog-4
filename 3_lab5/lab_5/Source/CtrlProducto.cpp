#include "../Header/CtrlProducto.h"
#include "../Header/CtrlVenta.h"

//Alta Producto
bool CtrlProducto::masDeUnProducto() {
	return !coleccionDeComida.empty();
}
void CtrlProducto::agregarProducto(string codigo, string descripcion, int precio) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->precio = precio;
}
void CtrlProducto::aceptarAltaProducto() {
	Producto *p = new Producto(codigo,descripcion,precio);
	Comida *c;
	c = p;
	coleccionDeComida.insert(make_pair(codigo, c));
}
set<DtProducto> CtrlProducto::agregarMenu(string codigo, string descripcion) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	map<string, Comida*>::iterator iter;
	set<DtProducto> res;
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end(); iter++) {
		DtComida*c = iter->second->darDataType();
		DtProducto *p = dynamic_cast<DtProducto*>(c);
		if (p!=NULL) {
			DtProducto dtp = *p;
			res.insert(dtp);
		}
		delete c;

	}
	return res;
}
void CtrlProducto::agregarProductoMenu(string codigo, int cantidad) {
	DtProductoMenu dtpm(codigo, cantidad);
	infoMP.insert(dtpm);
}
void CtrlProducto::aceptarAltaMenu() {
	map<string, Comida*>::iterator iterComida;
	set<DtProductoMenu>::iterator iter;

	set<MenuProducto*> productos;

	Menu *m = new Menu(this->codigo, this->descripcion);
	Comida *c;



	for (iter = infoMP.begin(); iter != infoMP.end(); iter++) {
		iterComida = coleccionDeComida.find(iter->getCodigo());
		c = iterComida->second;
		Producto *p = dynamic_cast<Producto*>(c);
		if (p) {
			p->asociarAMenu(m, iter->getCantidad());
		}
		else {
			throw (2);
		}

	}
	c = m;

	coleccionDeComida.insert(make_pair(codigo, c));

}
void CtrlProducto::cancelarAltaMenu() {
	infoMP.clear();
}

//Baja de Producto
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
void CtrlProducto::confirmarBaja() {
	CtrlVenta *cv = CtrlVenta::getInstance();

	map<string, Comida*>::iterator iter = coleccionDeComida.find(codigo);

	Comida*c = iter->second;

	try {
		cv->quitarComidaVenta(iter->second->getCodigo());

		c->darDeBajaComida();
		coleccionDeComida.erase(iter);
		delete c;
	}
	catch (int x) {
		if (x == 1) {
			cout << "existe una venta no facturada que tiene el producto que queres eliminar en quitarComidaVenta() ctrlVenta" << endl;
		}
		else {
			throw(x);
		}
	}
}



Comida* CtrlProducto::pedirComida(string codigo) {
	map<string, Comida*>::iterator i;
	i = coleccionDeComida.find(codigo);
	return i->second;
}

