#ifndef DTFACTURA_H
#define DTFACTURA_H

#include <iostream>
#include <set>
#include "../Header/DtComida.h"
#include "../Header/DtEmpleado.h"
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
	string getCodigo();
	DtFecha getFecha();
	DtHora getHora();
	set<DtComida> getComidaVendida();
	float getSubtotal();
	float getmontoTotal();
	float getSubtotalIVA();
	int getDescuento();

};

class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtDelivery getDelivery();

};


class DtFacturaLocal : public DtFactura {
private:
	DtMozo mozo;
public:
	DtMozo getMozo();

};





#endif // !DTFACTURA_H
