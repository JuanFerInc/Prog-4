#ifndef FABRICA_H
#define FABRICA_H	

#include <iostream>

#include "../Header/CtrlEmpleado.h"
#include "../Header/CtrlVenta.h"
#include "../Header/CtrlProducto.h"
#include "../Header/CtrlCliente.h"

using namespace std;

class Fabrica{
private:
	static Fabrica* instancia;
	
	Fabrica() {}
public:
	static Fabrica* getInstance();
	
	IVenta* getIVenta();
	IProducto* getIProducto();
	IEmpleado* getIEmpleado();
	ICliente* getICliente();
};
#endif