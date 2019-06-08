#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <set>



#include "../Header/Factura.h"


#include "../Header/VentaComida.h"


using namespace std;


class Venta{
protected:
	Factura* linkFactura;
    string nroVenta;
    static int IVA;
    int subtotoal;
    bool facturado;
	set<VentaComida*> comidaContenida;

public:
	Venta();
//setters
	void setNroVenta(string nroVenta);
	static void setIVA(int iva);

	void setSubtotal(int subtotal);
	void setFacturado(bool facturado);

//getters
	string getNroVenta();
	int getIVA();
	int getSubtotal();
	bool getFacturado();
	set<VentaComida> getComidaContenida();
	Factura* getLinkFactura();
	//otras

	//quita VentaProducto del set y lo elmina
	void borrarVentaProducto(string codigo);
	void finalizarVenta(Factura* factura);

	void borrarVentaComida(string codigo);
	//retorna true sii la venta tiene una comida con el codigo
	bool tieneComida(string codigo);

};


#endif