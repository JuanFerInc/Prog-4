#include "../Header/Comida.h"
#include "../Header/DtMenu.h"

class Menu :public Comida {
private:
	set<MenuProducto*> productosContenidos;
public:
	//geters
	set<MenuProducto*> getProductosContenidos();

	//otra
	bool esProducto();
	DtMenu darDataType();
};