#include "../Header/DtMenu.h"
class DtMenuVentas : public DtMenu {
private:
	int cantidad;

public:
	DtMenuVentas(string codig, string descripcion, int precio, int cantidad);
	int getCantidad();
	void print(std::ostream& out);

};