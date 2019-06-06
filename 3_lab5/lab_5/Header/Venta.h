#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <set>

#include "../Header/DtComida.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/Factura.h"
#include "../Header/Comida.h"
#include "../Header/IObserver.h"
#include "../Header/DtEstado.h"
#include "../Header/VentaComida.h"
#include "../Header/Cliente.h"



using namespace std;


class Venta{
private:
	Factura* linkFactura;
    string nroVenta;
    static int IVA;
    int subtotoal;
    bool facturado;
protected: 
	set<VentaComida*> comidaContenida;
public:
//setters
	void setNroVenta(string nroVenta);
	void setIVA(int iva);
	void setSubtotal(int subtotal);
	void setFacturado(bool facturado);

//getters
	string getNroVenta();
	int getIVA();
	int getSubtotal();
	bool getFacturado();
	set<VentaComida> getComidaContenida();

};



#endif