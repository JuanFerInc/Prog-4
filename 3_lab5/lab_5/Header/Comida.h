#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <strings>

#include "../Header/IObserver.h"
#include "../Header/Factura.h"

#include "../Header/DtEstado.h"
#include "../Header/DtComida.h"
#include "../Header/DtComidaVendida"


class Comida{
private:
    int precioÇ;
    string descripcion;
    string codigo;
public:
    virtual bool esProducto()=0;
    virtual DtComida darDataType()=0;
    bool sonIguales(codigo);
    void darDeBajaComida();

}

class Producto: public Comida{
public:
    bool esProducto()
    DtComida darDataType()
    asociarAMenu(m:Menu, cantidad:int)
    
}

class Menu:public Comida{
    
public:
    bool esProducto()
    DtComida darDataType()
    
}
