#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H



#include "../Header/DtComida.h"

class DtProducto : public DtComida {
private:
public:
	DtProducto() {};

	DtProducto(const DtProducto& producto);
	DtProducto(string codigo, string descripcion, int precioTotal);
	
	void print(std::ostream& out);
	bool operator<(const DtProducto& d)const;
};

#endif // !DTPRODUCTO