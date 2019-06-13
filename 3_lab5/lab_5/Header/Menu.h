#ifndef  MENU_H
#define MENU_H

#include "../Header/Comida.h"
#include "../Header/DtMenuVenta.h"
#include "../Header/MenuProducto.h"

class Menu :public Comida {
private:
	set<MenuProducto*> productosContenidos;
public:
	Menu(string nombre, string descripcion);

	//geters
	int getPrecio();

	set<MenuProducto*> getProductosContenidos();



	//otra
	void asociarmeAMenuProducto(MenuProducto *mp);

	DtComida* darDataType();

	bool desvincularM(MenuProducto *mp);

	void darDeBajaComida();

	DtMenuVenta* darDataVenta();
	~Menu();
};


#endif // ! MENU_H
