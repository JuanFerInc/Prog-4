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


using namespace std;

class CtrlVenta: public IVenta {
private:
	CtrlVenta* instancia;
	string codigo;
	int nroMesa, cantidad, nroEmpleado;
	set<int> Mesas;										//Wtf is this (manuel)
	map<string, DtComida> Comidas;
	map<string, Venta*> coleccionDeVenta;
	map<int, Mesa*> coleccionDeMesa;

	void ctrlVenta();
	
public:
	CtrlVenta* getInstance();
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
	void quitarComidaVenta(string codigo);
	void agregarMesaAVenta(int nroMesa);
	set<int> mostrarMesasSeleccionadas();
	void descartarVentasEnMesa();
	void mesasAsignadas(int nroEmpleado);
	void confirmarVentaEnMesas();
	DtFactura generarFactura(int nromesa, int descuento);
	void cancelarPedido(int nroVenta);
	void ultimasActualizaciones();
};

#endif 