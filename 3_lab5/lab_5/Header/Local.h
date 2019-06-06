#include "../Header/Venta.h"

class Local :public Venta {

public:
	bool hayComidaEnVenta(string codigo);
	set<DtComida> productosEnVenta();
	bool cantEsMayor(string codigo, int cantidad);
	void decrementarCantidad(string codigo, int cantidad);
	void eliminarComida(string codigo);
	bool tieneComida(string codigo);
	void borrarVentaProducto(string codigo);
	void desvincular(VentaComida vp);
	set<DtComidaVendida> darComidas();
	void aumentarCantidad(string codigo, int cantidad);
	void finalizarVenta(Factura* factura);
	bool noEstaFacturada();
	void agregarComida(Comida* c, int cantidad);

};