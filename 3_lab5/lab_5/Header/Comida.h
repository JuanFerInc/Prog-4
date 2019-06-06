#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>

#include "../Header/IObserver.h"
#include "../Header/Factura.h"

#include "../Header/DtEstado.h"
#include "../Header/DtComida.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/MenuProducto.h"

using namespace std;

class Comida{
protected:
    int precio;
    string descripcion;
    string codigo;
public:
//seters

	void setPrecio(int precio);
	void setDescripcion(string desc);
	void setCodigo(string codigo);
//geters

	int getPrecio();
	string getDescripcion();
	string getCodigo();

//Otras
    virtual bool esProducto() = 0;
    virtual DtComida* darDataType() = 0;
    bool sonIguales(string codigo);
    void darDeBajaComida();

};
#endif