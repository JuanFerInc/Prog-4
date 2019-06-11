#ifndef VENTACOMIDA_H
#define VENTACOMIDA_H	

#include <iostream>
#include "../Header/Comida.h"
#include "../Header/DtComidaVendida.h"


using namespace std;

class VentaComida {
private:
	int cantidad;
	Comida* linkComida;

public:

	VentaComida(Comida* c, int cantidad);

//seters
	void setCantidad(int cant);
//geters
	int getCantidad();

//Otras
	bool ventaContieneComida(string codigo);
	void incrementarCantidad(string codigo, int cantidad);
	void aumentoCantidad(int cantidad);

	DtComida* pedirDatatypeAComida();

	bool esMayor(string codigo, int cantidad);
	void bajarCantidad(string codigo, int cantidad);
	VentaComida* esComidaAEliminar(string codigo);
	bool estaLaComida(string codigo);

	//Retora true si la comida asociada a la venta comida tiene el mismo codigo
	bool tieneMismo(string codigo);

	DtComidaVendida* darDtComidayCantidad();


	void incrementarCantidadUnidadesVendidas();
	//Venta a Domicilio
	int darPrecio();
	DtComidaVendida pedirDatatypeDtComidaVendida();

};
#endif