#ifndef MESA_H
#define MESA_H	

#include <iostream>
#include "../Header/Comida.h"
#include "../Header/Mozo.h"
#include "../Header/DtFacturaLocal.h"




class Local;


using namespace std;

class Mesa {
private:
	Mozo *linkMozo;
	Local *linkLocal;
	int nroMesa;


public:
	//constructor
	Mesa(Mozo* linkMozo, Local* linkLocal, int nroMesa);

//geters
	int getNroMesa();
	Mozo* getMozo();
	Local *getLocal();

//Otras
	bool hayComidaEnMesa(string codigo);
	void aumentarCantidadComidaEnMesa(string codigo, int cantidad);
	void agregarComidaEnMesa(Comida* c, int cantidad);
	set<DtComida> productosEnVentaEnMesa();
	bool cantEsMayorEnMesa(string codigo, int cantidad);
	void decrementarCantidadEnMesaDeComida(string codigo, int cantidad);
	void eliminarComidaDeMesa(string codigo);

	
	void asociarAMozo(Mozo*m);
	void asociarALocal(Local *l);
	void desvincularmeDelLocal();
	DtFacturaLocal *facturar(int descuento);
	

};
#include "../Header/Local.h"

#endif