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

	CtrlProducto();

public:
	static CtrlProducto* getInstance();
	//Alta Producto

	//retorna true sii este contiene al menos un producto
	bool masDeUnProducto();

	//Ingresa los datos del nuevo producto que se ingresara al sistema
	//Pre: No existe producto con el mismo codigo
	//Post: El Sistema Recuerda lot atributos del Producto
	void agregarProducto(string codigo, string descripcion, int precio);

	////Ingresa al sistema el nuevo producto
	//Pre: El sistema tiene los datos del nuevo producto
	//Post: Se almacena en la memoria del sistema un nuevo instancia del producto
	void aceptarAltaProducto();

	// Se libera la memoria del sistema asociada al nuevo producto
	//Pre: El sistema tiene los datos del nuevo producto
	//Post: El sistema no tiene los datos del unevo producto
	void cancelarAltaProducto() = 0;

	//Ingresa los datos del nuevo menu que se ingresa al sistema
	//Pre: No existe instancia de menu con el mismo codigo en el sistema
	//Post: El sistema recuerda los datos del menu

	set<DtProducto> agregarMenu(string codigo, string descripcion);

	//Ingresa al sistema los productos que seran asociado al menu
	//Pre: Existe producto con el codigo ingresado
	//Post: El sistema recuerda el producto seleccionado
	void agregarProductoMenu(string codigo, int cantidad);

	//Ingresa al sistema el nuevo menu y los esocia con los productos que corresponde
	//Pre: El sistema tiene almacenado los datos del Meny y los productos con los que sera asociaco meditna el identificador codigo y la cantidad
	//de dicho producto que estan en el menu
	//Post: Se crea en la memoria del sistema una nueva instancia de Menu y se asocia con todos los productos que corresponda.
	//Tambien el sistme olvida todo lo recordado en este caso de uso.
	void aceptarAltaMenu();

	//Libera la memoria del sistema asociada al menu y los productos
	//Pre: El sistema tiene almacenado los datos del Menu y los productos con los que sera asociado mediante el identificador
	//codigo y la cantidad de dicho producto que estan en el menu
	//Post: El sistema olvida los datos del Menu y los productos recordad. 
	void cancelarAltaMenu();

	//Baja de Producto
	set<DtComida> listaDeComidaDisponible();
	void ingresarCodigo(string codigo);
	void cancelarBaja();
	void confirmarBaja();
	Comida* pedirComida(string codigo);
};

#endif