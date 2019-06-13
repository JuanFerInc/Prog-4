#ifndef DTPRODUCTOVENTA_H
#define DTPRODUCTOVENTA_H

#include "../Header/DtProducto.h"
#include <string>

class DtProductoVenta : public DtProducto {
private:
	int cantidad;

public:

	DtProductoVenta(string codig, string descripcion, int precio, int cantidad);
	DtProductoVenta(DtProducto producto, int cantidad);
	//geters
	int getCantidad();
	//impresion

	
	bool operator<(const DtProductoVenta& d)const;
	
	void print(ostream& out);

};


#endif // !DTPRODUCTOVENTA_H

