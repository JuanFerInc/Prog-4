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


using namespace std;


class Venta{
private:
    string nroVenta;
    static int IVA;
    int subtotoal;
    bool facturado;
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
};


class Domicilio : public Venta {
public:
	void agregar(IObserver observer);
	void eliminar(IObserver observer);
	void cancelarPedido();
	void siguienteEstado();
	DtEstadoTerminado darDatatypeTermnado(DtEstado estado);
	
};

class Local :public Venta {

public:
	bool hayComidaEnVenta(string codigo);
	set<DtComida> productosEnVenta();
	bool cantEsMayor(string codigo,int cantidad);
	void decrementarCantidad(string codigo,int cantidad);
	void eliminarComida(string codigo);
	bool tieneComida(string codigo);
	void borrarVentaProducto(string codigo);
	void desvincular( VentaComida vp);
	set<DtComidaVendida> darComidas();
	void aumentarCantidad(string codigo,int cantidad);
	void finalizarVenta(Factura factura);
	bool noEstaFacturada();
	void agregarComida(Comida c,int cantidad);
};

#endif