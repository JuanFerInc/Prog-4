#ifndef IPRODUCTO_H
#define IPRODUCTO_H

#include <iostream>
#include "../Header/DtFactura.h"
#include "../Header/DtComida.h"
#include "../Header/Comida.h"



using namespace std;

class IVenta{
    public:
        virtual bool masDeUnProducto() =0;
        virtual void agregarProducto(string codigo,string descripcion,int precio) =0;
        virtual void aceptarAltaProducto() =0;
        virtual void cancelarAltaProducto() =0;
        virtual DtProducto* agregarMenu(string codigo,string descripcion) =0; (to be continued)
        virtual void agregarProductoMenu(string codigo,int cantidad) =0;
        virtual void aceptarAltaMenu() =0;
        virtual void cancelarAltaMenu() =0;
        virtual void darDataType()  =0;
        virtual DtComida* listaDeComidaDisponible() =0;
        virtual void ingresarCodigo(string codigo) =0;
        virtual void cancelarBaja() =0;
        virtual void confirmarBaja() =0;
        virtual Comida pedirComida(string codigo) =0;
};

#endif


