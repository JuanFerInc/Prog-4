#ifndef LOCAL_H
#define LOCAL_H
#include <map>
#include "../Header/Venta.h"
#include "../Header/Mozo.h"
#include "../Header/Mesa.h"
#include "../Header/DtComida.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/DtMozo.h"
#include "../Header/Comida.h"
#include "../Header/VentaComida.h"


class Local :public Venta {
private:
	map<int, Mesa*> setsito;
	Mozo *linkMozo;
public:

	Local(map<int,Mesa*> mesas,string nroVenta, Mozo *mozo );
	

	bool hayComidaEnVenta(string codigo);
	set<DtComida> productosEnVenta();
	bool cantEsMayor(string codigo, int cantidad);
	void decrementarCantidad(string codigo, int cantidad);
	void eliminarComida(string codigo);
	void desvincular(VentaComida vp);
	set<DtComidaVendida> darComidas();
	void aumentarCantidad(string codigo, int cantidad);
	
	bool noEstaFacturada();

	//agrega la comida a la venta local e ingrementa el subtotal
	void agregarComida(Comida* c, int cantidad);
	void desvincularMesaDeMiEnVentaActual();
	DtMozo getDtMozo();
};

#endif