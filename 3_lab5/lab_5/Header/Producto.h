#include "../Header/Comida.h"
#include "../Header/Menu.h"

class Producto : public Comida {
private:
	set<MenuProducto*> esContenidoEn;

public:
	//geters
	set<MenuProducto*> getEsContenidoEn();

	//Otras
	void asociarAMenu(Menu m, int cantidad); //cantidad es DtProductoMenu.getCantidad()
	bool esProducto();
	DtProducto darDataType();
	void darDeBajaComida();

};
