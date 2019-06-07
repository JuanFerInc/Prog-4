#include "../Header/DtComida.h"
#include "../Header/DtProductoVenta.h"

class DtMenu : public DtComida {
private:
	set<DtProductoVenta> productosDeMenu;

public:
	DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos);
	DtMenu(const DtMenu& m);
	map<string, DtProductoVenta*> getProductosDeMenu();
	void print(std::ostream&);
};

