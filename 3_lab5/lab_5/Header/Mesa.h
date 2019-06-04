#ifndef MESA_H
#define MESA_H	

#include <iostream>
#include "../Header/Comida.h"
#include "../Header/DtComida.h"
#include "../Header/Local.h"
#include "../Header/DtFactura.h"




using namespace std;

class Mesa {
private:
	Local* linkLocal;
	int nroMesa;

public:
//seters
	void setNroMesa(int nroMesa);

//geters
	int getNroMesa();

//Otras
	bool hayComidaEnMesa(string codigo);
	void aumentarCantidadComidaEnMesa(string codigo, int cantidad);
	void agregarComidaEnMesa(Comida c, int cantidad);
	set<DtComida> productosEnVentaEnMesa();
	bool cantEsMayorEnMesa(string codigo, int cantidad);
	void decrementarCantidadEnMesaDeComida(string codigo, int cantidad);
	void eliminarComidaDeMesa(string codigo);
	DtFactura facturar(int descuento);
	
};
#endif