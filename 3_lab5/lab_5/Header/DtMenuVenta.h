#include "../Header/DtMenu.h"
class DtMenuVenta : public DtMenu {
private:
	int cantidad;

public:
	DtMenuVenta(string codigo, string descripcion, int precio, int cantidad, set<DtProductoVenta> productosDeMenu);
	int getCantidad();


};