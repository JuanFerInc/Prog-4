#include "../Header/CtrlProducto.h"
#include "../Header/CtrlVenta.h"


CtrlProducto*CtrlProducto::getInstance() {
	if (instance == NULL) {
		instance = new CtrlProducto();

	}


CtrlProducto::CtrlProducto(){
}
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

void CtrlProducto::cancelarAltaProducto() {

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

	//verificamos que todos los codigod pasados corresponden a un producto
	for (iter = infoMP.begin(); iter != infoMP.end(); iter++) {
		iterComida = coleccionDeComida.find(iter->getCodigo());

		if (iterComida == coleccionDeComida.end()) {
			cout << iter->getCodigo() << endl;
			throw(3);
		}

		c = iterComida->second;
		Producto *p = dynamic_cast<Producto*>(c);
		if (p == NULL) {
			throw(5);
		}

	}
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
	for (iter = infoMP.begin(); iter != infoMP.end(); iter++) {
		iterComida = coleccionDeComida.find(iter->getCodigo());
		c = iterComida->second;
		Producto *p = dynamic_cast<Producto*>(c);
		p->asociarAMenu(m, iter->getCantidad());
	}

	c = m;

	coleccionDeComida.insert(make_pair(codigo, c));
	
	infoMP.clear();
}


void CtrlProducto::cancelarAltaMenu(){
	this->infoMP.clear();
}

//Baja de Producto
set<DtComida> CtrlProducto::listaDeComidaDisponible() {
	map<string,Comida*>::iterator iter;
	set<DtComida> res;

	//puede ser ++iter
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end();iter++) {
		DtComida *c = iter->second->darDataType();
		DtProducto *p = dynamic_cast<DtProducto*>(c);
		DtMenu *m = dynamic_cast<DtMenu*>(c);
		if (p != NULL) {
			DtProducto resp = *p;
			res.insert(resp);
		}
		else {
			DtMenu resm = *m;
			res.insert(resm);
		}

		
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

Comida* CtrlProducto::pedirComida(string codigo){
	map<string, Comida*>::iterator i;
	i = coleccionDeComida.find(codigo);
	return i->second;
}

bool CtrlProducto::existeComida(string codigo) {
	bool encontrado = false;
	this->codigo = codigo;
	map<string, Comida*>::iterator iter;
	iter = coleccionDeComida.find(codigo);
	if(iter!= coleccionDeComida.end()){
		encontrado = true;
	}
	else {
		codigo.clear();
	}
}


DtComida* CtrlProducto::ingresarCodigoParaInfo(){
	map<string, Comida*>::iterator iter;
	iter = coleccionDeComida.find(this->codigo);
	DtComida* res = iter->second->darDataVenta();
	codigo.clear();
	return res;
}