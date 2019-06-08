#include "../Header/DtComida.h"
#include "../Header/DtProductoVenta.h"

class DtMenu : public DtComida {
private:
	set<DtProductoVenta> productosDeMenu;

public:
	DtMenu();
	//Contructor por copia
	DtMenu(const DtMenu &m);

	DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos);

	//geters

	map<string, DtProductoVenta*> getProductosDeMenu();
	virtual void print(std::ostream& out);
};

