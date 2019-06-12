#ifndef DTFACTURA_H
#define DTFACTURA_H

#include <iostream>
#include <set>


#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"


using namespace std;

class DtFactura {
private:

	string codigo;			//Es el nroVenta
	DtFecha fecha;
	DtHora hora;
	set<DtComidaVendida> comidaVendida;
	float subtotal, montoTotal, montoTotalIVA; //montoTotal = subtotal* 0.descuento ; montoTotalIVA = montoTotal* 0.IVA
	int descuento;

public: 
	DtFactura(const DtFactura &dtf);
	DtFactura(string nroFactura, DtFecha fecha, DtHora hora, set<DtComidaVendida> comidaVendida, float subtotal, float montoTotal, float montoTotalIVA, int descuento);
	string getCodigo();
	DtFecha getFecha();
	DtHora getHora();
	set<DtComidaVendida> getComidaVendida();
	float getSubtotal();
	float getmontoTotal();
	float getSubtotalIVA();
	int getDescuento();

	friend std::ostream& operator<<(std::ostream& out, DtFactura *info);
	virtual void print(ostream& out);

};


#endif // !DTFACTURA_H
