#ifndef IVENTA_H
#define IVENTA_H

#include <iostream>

#include "../Header/DtComida.h"
#include "../Header/DtFacturaResumen.h"
#include "../Header/DtFacturaDomicilio.h"

class IVenta{
    public:
        virtual void ingresarNroMesa(int nroMesa) =0;
        virtual void seleccionarComida(string codigo, int cantidad) =0;
        virtual bool existeComidaEnVenta() =0;
        virtual void incrementarCantidad() =0;
        virtual void agregarPorPrimeraVez() =0;
        virtual void descartarAgregado() =0;
        virtual void liberarnroMesa() =0;
        virtual set<DtComida> productosEnVentaEnMesa(int nroMesa) =0;
        virtual bool cantidadEsMayor() =0;
        virtual void disminuirCantidad() =0;
        virtual void eliminarComidaDeVenta() =0;
        virtual void descartarEliminacion() =0;
        virtual void quitarComidaVenta(string codigo) =0;
        virtual void agregarMesaAVenta(int nroMesa) =0;
        virtual set<int> mostrarMesasSeleccionadas() =0;
        virtual void descartarVentasEnMesa() =0;

		//retorna las mesas libre asignadas al mozo
        virtual set<int> mesasAsignadas(int nroEmpleado) =0;
        virtual void confirmarVentaEnMesas() =0;
        virtual DtFactura* generarFactura(int nromesa,int descuento) =0;
        
		virtual void cancelarPedido(int nroVenta) = 0;
		virtual void siguienteEstado(int nroVenta) = 0;
		virtual void siguienteEstado(int nroVenta, DtHora horita) = 0;
        
        //Retorna un DtFacturaResumen que contiene el total de sumar todas las
        //facturas de ese dia y las facturas de ese dia
        virtual DtFacturaResumen resumenDelDia(int d, int m, int a) = 0;        
        //Venta a Domicilio
        virtual bool iniciarVentaADomicilio(string tel) = 0;
        virtual void seleccionarComida2(string codigo, int cantidad) = 0;
        virtual set<DtDelivery*> listarRepartidores() = 0;
        virtual void seleccionarRepartidor(int nroEmpleado) = 0;
        virtual void cancelarVentaADomicilio() = 0;
        virtual void confirmarVentaADomicilio() = 0;
		virtual void confirmarVentaADomicilio(DtHora horita) = 0;
        virtual DtFacturaDomicilio facturarVentaADomicilio(int descuento) = 0;
        virtual DtFactura facturarVentaADomicilioSinDelivery(int descuento) = 0;

		//incializar mesa predeterminado
		virtual void iniciliazarMesas() = 0;
};

#endif