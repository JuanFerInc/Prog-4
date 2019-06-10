#ifndef DTFACTURA_H
#define DTFACTURA_H

#include <iostream>
#include <set>
#include "../Header/DtComida.h"
#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"


using namespace std;

class DtFactura {
private:

	string codigo;			//Es el nroVenta
	DtFecha fecha;
	DtHora hora;
	set<DtComida> comidaVendida;
	float subtotal, montoTotal, montoTotalIVA;
	int descuento;

public: 
	DtFactura(const DtFactura &dtf);
	DtFactura(string nroFactura, DtFecha fecha, DtHora hora, set<DtComida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento);
	string getCodigo();
	DtFecha getFecha();
	DtHora getHora();
	set<DtComida> getComidaVendida();
	float getSubtotal();
	float getmontoTotal();
	float getSubtotalIVA();
	int getDescuento();

};


#endif // !DTFACTURA_H
