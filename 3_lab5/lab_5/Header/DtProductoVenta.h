#pragma once
#include "../Header/DtProducto.h"

class DtProductoVenta : public DtProducto {
private:
	int cantidad;

public:

	DtProductoVenta(DtProducto producto, int cantidad);
	//geters
	int getCantidad();
	//impresion
	void print(std::ostream& out);



};
