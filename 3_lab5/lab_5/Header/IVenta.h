#ifndef IVENTA_H
#define IVENTA_H

#include <iostream>
#include "../Header/DtFactura"
#include "../Header/DtComida"

class IVenta{
    public:
        virtual void ingresarNroMesa(int nroMesa) =0;
        virtual void seleccionarComida(string codigo, int cantidad) =0;
        virtual bool existeComidaEnVenta() =0;
        virtual void incrementarCantidad() =0;
        virtual void agregarPorPrimeraVez() =0;
        virtual void descartarAgregado() =0;
        virtual void liberarnroMesa() =0;
        virtual DtComida* productosEnVentaEnMesa(int nroMesa) =0; (To be continued)
        virtual bool cantidadEsMayor() =0;
        virtual void disminuirCantidad() =0;
        virtual void eliminarComidaDeVenta() =0;
        virtual void descartarEliminacion() =0;
        virtual void quitarComidaVenta(string codigo) =0;
        virtual void agregarMesaAVenta(int nroMesa) =0;
        virtual int* mostrarMesasSeleccionadas() =0; (to be continued)
        virtual void descartarVentasEnMesa() =0;
        virtual void mesasAsignadas(int nroEmpleado) =0;
        virtual void confirmarVentaEnMesas() =0;
        virtual DtFactura generarFactura(int nromesa,int descuento) =0;
        virtual void cancelarPedido(int nroVenta) =0;
        virtual void ultimasActualizaciones() =0;
};

#endif


