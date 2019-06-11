#include "../Header/Venta.h"
#include "../Header/Mesa.h"

class Local :public Venta {
private:
	map<int, Mesa> setsito;
	Mozo* linkMozo;
public:
	Local(map<int,Mesa>, Mozo* mozo);
	
	bool hayComidaEnVenta(string codigo);
	set<DtComida> productosEnVenta();
	bool cantEsMayor(string codigo, int cantidad);
	void decrementarCantidad(string codigo, int cantidad);
	void eliminarComida(string codigo);
	void desvincular(VentaComida vp);
	set<DtComidaVendida> darComidas();
	void aumentarCantidad(string codigo, int cantidad);
	
	bool noEstaFacturada();
	void agregarComida(Comida* c, int cantidad);

};