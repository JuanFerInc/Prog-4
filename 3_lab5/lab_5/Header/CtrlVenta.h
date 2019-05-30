#ifndef CTRLVENTA_H
#define CTRLVENTA_H	

#include <iostream>

#include <map>
#include <set>
#include "../Header/IVenta.h"
#include "../Header/DtComida.h"
#include "../Header/DtFactura.h"
#include "../Header/Empleado.h"

using namespace std;

class CtrlVenta: public IVenta {
private:
	string codigo;
	int nroMesa, cantidad, nroEmpleado;
	CtrlVenta* instancia;
	set<int> Mesas;
	map<string, DtComida> Comidas;


	
public:
	CtrlVenta* getInstance();
	void ingresarNroMesa(int nroMesa);
	void seleccionarComida(string codigo, int cantidad);
	bool existeComidaEnVenta();
	void incrementarCantidad();
	void agregarPorPrimeraVez();
	void descartarAgregado();
	void liberarnroMesa();
	DtComida* productosEnVentaEnMesa(int nroMesa); (To be continued)
	bool cantidadEsMayor();
	void disminuirCantidad();
	void eliminarComidaDeVenta();
	void descartarEliminacion();
	void quitarComidaVenta(string codigo);
	void agregarMesaAVenta(int nroMesa);
	int* mostrarMesasSeleccionadas(); (to be continued)
	void descartarVentasEnMesa();
	void mesasAsignadas(int nroEmpleado);
	void confirmarVentaEnMesas();
	DtFactura generarFactura(int nromesa, int descuento);
	void cancelarPedido(int nroVenta);
	void ultimasActualizaciones();
};

#endif 