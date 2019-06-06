#include "../Header/DtComida.h"
class DtProducto : public DtComida {
private:
public:
	DtProducto(const DtProducto& producto);
	DtProducto(string codigo, string descripcion, int precioTotal);
	void print(std::ostream&);

};
