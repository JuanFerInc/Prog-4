#pragma once
#include "../Header/DtProducto.h"

class DtProductoVenta : public DtProducto {
private:
	int cantidad;

public:

	DtProductoVenta(string codig, string descripcion, int precio, int cantidad);
	DtProductoVenta(DtProducto producto, int cantidad);
	//geters
	int getCantidad();
	//impresion
	void operator<<(ostream& out);



};
