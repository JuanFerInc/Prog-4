#include "../Header/DtComida.h"


class DtMenu : public DtComida {
private:
	set<DtProductoVenta> productosDeMenu;

public:
	DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos);
	map<string, DtProductoVenta*> getProductosDeMenu();
	void print(std::ostream&);
};

