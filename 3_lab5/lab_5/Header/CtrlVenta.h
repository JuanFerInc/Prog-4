#ifndef CTRLVENTA_H
#define CTRLVENTA_H	

#include <iostream>

#include <map>
#include <set>
#include "../Header/IVenta.h"
#include "../Header/DtComida.h"
#include "../Header/DtFactura.h"
#include "../Header/Empleado.h"
#include "../Header/Venta.h"
#include "../Header/Mesa.h"
#include "../Header/CtrlProducto.h"
#include "../Header/CtrlEmpleado.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFacturaDomicilio.h"
#include "../Header/CtrlCliente.h"
#include "../Header/Recibido.h"
#include "../Header/Pedido.h"


using namespace std;

class CtrlVenta: public IVenta {
private:
	static CtrlVenta* instancia;
	string codigo, nroEmpleado;
	int nroMesa, cantidad, nroVenta;
	set<int> Mesas;										//Wtf is this (manuel)
	map<string, DtComida> Comidas;
	map<string, Venta*> coleccionDeVenta;
	map<int, Mesa*> coleccionDeMesa;
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
	void cancelarPedido(int nroVenta);
	void ultimasActualizaciones();

	//Venta a Domicilio
	bool iniciarVentaADomicilio(string tel);
	void seleccionarComida2(string codigo, int cantidad);
	set<DtDelivery> listarRepartidores();
	void seleccionarRepartidor(int nroEmpleado);
	void cancelarVentaADomicilio();
	void confirmarVentaADomicilio();
	DtFacturaDomicilio facturarVentaADomicilio(int descuento);

};

#endif 