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

	string codigo;
	DtFecha fecha;
	DtHora hora;
	set<DtComida> comidaVendida;
	float subtotal, montoTotal, montoTotalIVA;
	int descuento;

public: 
	DtFactura(const DtFactura &dtf);
	string getCodigo();
	DtFecha getFecha();
	DtHora getHora();
	set<DtComida> getComidaVendida();
	float getSubtotal();
	float getmontoTotal();
	float getSubtotalIVA();
	int getDescuento();
	virtual void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, DtFactura*info);
};


#endif // !DTFACTURA_H
