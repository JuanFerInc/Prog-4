#include "../Header/DtComida.h"
class DtProducto : public DtComida {
private:
public:
	DtProducto();

	DtProducto(const DtProducto& producto);
	DtProducto(string codigo, string descripcion, int precioTotal);
	virtual void print(std::ostream& out);

};
