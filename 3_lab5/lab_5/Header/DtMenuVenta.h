#ifndef DTMENUVENTA_H
#define DTMENUVENTA_H


#include "../Header/DtMenu.h"


class DtMenuVenta : public DtMenu {
private:
	int cantidad;

public:
	DtMenuVenta(string codigo, string descripcion, int precio, int cantidad, set<DtProductoVenta*> productosDeMenu);
	int getCantidad();

	
	void print(ostream& out);
};

#endif // !DTMENUVENTA_H
