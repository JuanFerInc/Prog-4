#include "../Header/CtrlProducto.h"
#include "../Header/Producto.h"
#include "../Header/Comida.h"
#include "../Header/Menu.h"				
#include "../Header/DtProducto.h"
#include "../Header/DtComida.h"
#include "../Header/DtProductoMenu.h"
#include "../Header/MenuProducto.h"
#include "../Header/DtMenu.h"
#include "../Header/CtrlVenta.h"


CtrlProducto*CtrlProducto::instance = NULL;

CtrlProducto*CtrlProducto::getInstance() {
	if (instance == NULL) {
		instance = new CtrlProducto();

	}
	return instance;
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
	infoMP.clear();
}

set<DtProducto*> CtrlProducto::agregarMenu(string codigo, string descripcion) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	map<string, Comida*>::iterator iter;
	set<DtProducto*> res;
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end(); iter++) {
		DtComida*c = iter->second->darDataType();
		DtProducto *p = dynamic_cast<DtProducto*>(c);
		if (p!=NULL) {
			DtProducto *dtp = p;
			res.insert(dtp);
		}
		else {
			delete c;
		}
		

	}
	return res;
}

void CtrlProducto::agregarProductoMenu(string codigo, int cantidad) {
	set<DtProductoMenu>::iterator iter;

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
			throw(2);
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

	c = m;

	coleccionDeComida.insert(make_pair(codigo, c));
	
	infoMP.clear();
}


void CtrlProducto::cancelarAltaMenu(){
	this->infoMP.clear();
}

//Baja de Producto
set<DtComida*> CtrlProducto::listaDeComidaDisponible() {
	map<string,Comida*>::iterator iter;
	set<DtComida*> res;

	//puede ser ++iter
	for (iter = coleccionDeComida.begin(); iter != coleccionDeComida.end();iter++) {
		DtComida *c = iter->second->darDataType();
		res.insert(c);
		
		/*
		DtProducto *p = dynamic_cast<DtProducto*>(c);
		DtMenu *m = dynamic_cast<DtMenu*>(c);
		
		
		if (p != NULL) {
			
			res.insert(p);
		}
		else {
			
			res.insert(m);
		}
		*/
		
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
	return encontrado;
}


DtComida* CtrlProducto::ingresarCodigoParaInfo(){
	map<string, Comida*>::iterator iter;
	iter = coleccionDeComida.find(this->codigo);
	DtComida* res = iter->second->darDataVenta();
	codigo.clear();
	return res;
}
void CtrlProducto::quitarMenu(string codigo) {
	map<string, Comida*>::iterator iter = coleccionDeComida.find(codigo);	
	this->coleccionDeComida.erase(iter);
}

void CtrlProducto::agregarDatosPredef() {
	//Productos
	Producto *p = new Producto("1", "Pizza con muzzarella", 130);
	Comida *c;
	c = p;
	coleccionDeComida.insert(make_pair("1", c));

	p = new Producto("2", "Milanesa con guarnicion", 230);
	c = p;
	coleccionDeComida.insert(make_pair("2", c));

	p = new Producto("3", "Coca Cola 1.25L", 95);
	c = p;
	coleccionDeComida.insert(make_pair("3", c));

	p = new Producto("4", "Empanada Capresse", 72);
	c = p;
	coleccionDeComida.insert(make_pair("4", c));

	p = new Producto("5", "Flan con dulce de leche", 110);
	c = p;
	coleccionDeComida.insert(make_pair("5", c));

	//Menues//


	Comida* d;

	Menu* m = new Menu("6", "Combo Pizza");
	d = coleccionDeComida.find("1")->second;
	Producto *a = dynamic_cast<Producto*> (d);

	a->asociarAMenu(m, 1);

	d = coleccionDeComida.find("3")->second;
	a = dynamic_cast<Producto*> (d);
	a->asociarAMenu(m, 1);

	c = m;
	coleccionDeComida.insert(make_pair("6", c));


	//Next	

	m = new Menu("7", "Combo Empanadas");
	a = dynamic_cast<Producto*> (d);
	d = coleccionDeComida.find("3")->second;
	a->asociarAMenu(m, 1);

	d = coleccionDeComida.find("4")->second;
	a = dynamic_cast<Producto*> (d);
	a->asociarAMenu(m, 3);

	c = m;
	coleccionDeComida.insert(make_pair("7", c));
}