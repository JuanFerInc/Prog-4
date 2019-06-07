#include "../Header/Comida.h"
#include "../Header/Menu.h"
#include "../Header/MenuProducto.h"

class Producto : public Comida {
private:
	int precio;
	set<MenuProducto*> esContenidoEn;

public:
	//Contructor
	Producto(string codigo, string descripcion, int precio);
	//geters
	int getPrecio();
	set<MenuProducto*> getEsContenidoEn();
	//set
	void setPrecio(int precio);
	//Otras
	void asociarAMenu(Menu *m, int cantidad); 
	
	//Polymorphic
	bool esProducto();	

	DtProducto *darDataType();
	void darDeBajaComida();

};
