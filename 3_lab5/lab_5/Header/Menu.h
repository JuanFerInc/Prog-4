#ifndef  MENU_H
#define MENU_H
#include "../Header/Comida.h"
class MenuProducto;

class MenuProducto;

class Menu :public Comida {
private:
	set<MenuProducto*> productosContenidos;
public:
	Menu(string nombre, string descripcion);

	//geters
	int getPrecio();
	set<MenuProducto*> getProductosContenidos();
	int getPrecio();
	//otra
	void asociarmeAMenuProducto(MenuProducto *mp);

	DtMenu* darDataType();
	bool desvincularM(MenuProducto *mp);
	void darDeBajaComida();
};

#include "../Header/MenuProducto.h"

#endif // ! MENU_H
