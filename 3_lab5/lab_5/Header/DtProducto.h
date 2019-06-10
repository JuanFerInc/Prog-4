#include "../Header/DtComida.h"
class DtProducto : public DtComida {
private:
public:
	DtProducto();

	DtProducto(const DtProducto& producto);
	DtProducto(string codigo, string descripcion, int precioTotal);
	ostream& operator<<(ostream& out, DtProducto* prod);
	void print(std::ostream& out);

};
