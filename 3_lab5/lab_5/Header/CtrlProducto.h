#ifndef CTRLPRODUCTO_H
#define CTRLPRODUCTO_H

#include <iostream>
#include <set>
#include <map>

#include "../Header/IProducto.h"
#include "../Header/DtProductoMenu.h"
#include "../Header/DtProducto.h"
#include "../Header/DtComida.h"
#include "../Header/Menu.h"
#include "../Header/Producto.h"

using namespace std;

class CtrlProducto :public IProducto {

private:
	static CtrlProducto* instance;
	DtProducto infoProducto;
	DtMenu infoMenu;
	string codigo;
	string descripcion;
	int precio;
	set<DtProductoMenu> infoMP;
	map<string, Comida*> coleccionDeComida;

	void ctrlProducto();

public:
	static CtrlProducto* getInstancie();
	//Alta Producto

	//retorna true sii este contiene al menos un producto
	bool masDeUnProducto();
	//El controlador recuerda los atributos que le pasaron
	void agregarProducto(string codigo, string descripcion, int precio);

	void aceptarAltaProducto();
	void cancelarAltaProducto() = 0;
	set<DtProducto> agregarMenu(string codigo, string descripcion);
	void agregarProductoMenu(string codigo, int cantidad);
	void aceptarAltaMenu();
	void cancelarAltaMenu();
	//Baja de Producto
	set<DtComida> listaDeComidaDisponible();
	void ingresarCodigo(string codigo);
	void cancelarBaja();
	void confirmarBaja();
	Comida *pedirComida(string codigo);
};

#endif