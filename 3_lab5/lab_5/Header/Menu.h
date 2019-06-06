#ifndef  MENU_H
#define MENU_H


#include "../Header/Comida.h"
class MenuProducto;

class Menu :public Comida {
private:
	set<MenuProducto*> productosContenidos;
public:
	Menu(string nombre, string descripcion);
	//geters
	set<MenuProducto*> getProductosContenidos();

	//otra
	void asociarmeAMenuProducto(MenuProducto *mp);
	bool esProducto();
	DtComida *darDataType();
	bool desvincularM();
	void darDeBajaComida();

};

#include "../Header/MenuProducto.h"
#endif // ! MENU_H
