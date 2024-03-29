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
    static int IVA ;
    int subtotal;
    bool facturado;
	set<VentaComida*> comidaContenida;

public:


	Venta(string nroVenta);



	Venta(string nroVenta, set<VentaComida*> comidaContenida,int subtotal); //? no se usa en ningun lado
//setters
	void setNroVenta(string nroVenta);
	static void setIVA(int iva);

	void setSubtotal(int subtotal);
	void setFacturado(bool facturado);

//getters
	string getNroVenta();
	static int getIVA();
	int getSubtotal();
	bool getFacturado();
	set<VentaComida*> getComidaContenida();
	Factura* getLinkFactura();
	//otras

	//quita VentaProducto del set y lo elmina
	void borrarVentaProducto(string codigo);

	//Asocia la venta con una factura
	void finalizarVenta(Factura* factura);

	void borrarVentaComida(string codigo);
	//retorna true sii la venta tiene una comida con el codigo
	bool tieneComida(string codigo);
	
	virtual ~Venta() {};
};



#endif

