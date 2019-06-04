#ifndef CTRLPRODUCTO_H
#define CTRLPRODUCTO_H

#include <iostream>
#include <set>
#include <map>

#include "../Header/IProducto.h"
#include "../Header/DtProductoMenu.h"
#include "../Header/DtProducto.h"
#include "../Header/DtComida.h"
#include "../Header/Comida.h"



using namespace std;

class CtrlProducto:public IProducto {
private:
	CtrlProducto* instance;
	DtProducto infoProducto;
	DtMenu infoMenu;
	string codigo;
	set<DtProductoMenu> infoMP;
	map<string, Comida*> coleccionDeComida;

	void ctrlProducto();

public:
	CtrlProducto* getInstancie();
	bool masDeUnProducto();
	void agregarProducto(string codigo, string descripcion, int precio);
	void aceptarAltaProducto();
	void cancelarAltaProducto();
	set<DtProducto> agregarMenu(string codigo, string descripcion);
	void agregarProductoMenu(string codigo, int cantidad);
	void aceptarAltaMenu();
	void cancelarAltaMenu();
	void darDataType();
	set<DtComida> listaDeComidaDisponible();
	void ingresarCodigo(string codigo);
	void cancelarBaja();
	void confirmarBaja();
	Comida *pedirComida(string codigo);

	
};

#endif