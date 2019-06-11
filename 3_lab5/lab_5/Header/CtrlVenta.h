#ifndef CTRLVENTA_H
#define CTRLVENTA_H	

#include <iostream>

#include <map>
#include <set>
#include "../Header/IVenta.h"
#include "../Header/CtrlProducto.h"
#include "../Header/CtrlEmpleado.h"
#include "../Header/CtrlCliente.h"

#include "../Header/Empleado.h"
#include "../Header/Venta.h"
#include "../Header/Mesa.h"
#include "../Header/Recibido.h"
#include "../Header/Pedido.h"

#include "../Header/DtComida.h"
#include "../Header/DtFactura.h"
#include "../Header/DtFacturaResumen.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFacturaDomicilio.h"




using namespace std;

class CtrlVenta: public IVenta {
private:
	static CtrlVenta* instancia;
	string codigo, nroEmpleado;

	int nroMesa, cantidad, nroVenta,genNroVenta;
	map<int, Mesa*> coleccionDeMesa;
	set<int> Mesas;		
	
	map<string, DtComida> Comidas;
	map<string, Venta*> coleccionDeVenta;

	set<DtProductoMenu> coleccionProductosADomicilio;
	bool retiraEnElLocal;
	CtrlVenta();

public:
	static CtrlVenta* getInstance();

	void ingresarNroMesa(int nroMesa);
	void seleccionarComida(string codigo, int cantidad);
	bool existeComidaEnVenta();
	void incrementarCantidad();
	void agregarPorPrimeraVez();
	void descartarAgregado();
	void liberarnroMesa();
	set<DtComida> productosEnVentaEnMesa(int nroMesa);
	bool cantidadEsMayor();
	void disminuirCantidad();
	void eliminarComidaDeVenta();
	void descartarEliminacion();

	//tira una expeccion si alguna de las ventas que cointiene la comida asociada al coidgo no fue facturada
	void quitarComidaVenta(string codigo);
	
	//Iniciar Venta en Mesa
	void agregarMesaAVenta(int nroMesa);
	set<int> mostrarMesasSeleccionadas();
	void descartarVentasEnMesa();
	set<int> mesasAsignadas(int nroEmpleado);

	void confirmarVentaEnMesas();
	DtFactura generarFactura(int nromesa, int descuento);
	//Cancela el pedido a domicilio
	void cancelarPedido(int nroVenta);

	//Retorna un DtFacturaResumen que contiene el total de sumar todas las
	//facturas de ese dia y las facturas de ese dia
	DtFacturaResumen resumenDelDia(int d, int m, int a);


	//retorna un puter a coleccion de mesa
	map<int, Mesa*> *getColeccionDeMesa();

	//Venta a Domicilio
	bool iniciarVentaADomicilio(string tel);
	void seleccionarComida2(string codigo, int cantidad);
	set<DtDelivery> listarRepartidores();
	void seleccionarRepartidor(int nroEmpleado);
	void cancelarVentaADomicilio();
	void confirmarVentaADomicilio();
	DtFacturaDomicilio facturarVentaADomicilio(int descuento);
	DtFactura facturarVentaADomicilioSinDelivery(int descuento);

};

#endif 