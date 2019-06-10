#include "../Header/DtMenu.h"
class DtMenuVentas : public DtMenu {
private:
	int cantidad;

public:
	DtMenuVentas(int cantidad, DtProducto dataproducto);
	int getCantidad();


};