#pragma once
#include "../Header/DtProducto.h"

class DtProductoVenta : public DtProducto {
private:
	int cantidad;

public:

	DtProductoVenta(DtProducto producto, int cantidad);
	int getCantidad();


};
