#ifndef FACTURA_H
#define FACTURA_H


#include <set>
#include <iostream>

#include "../Header/DtFecha"
#include "../Header/DtHora"
#include "../Header/DtComidaVendida"
#include "../Header/DtFactura"

using namespace std;

class Factura {
private:
    DtFecha fecha;
    DtHora hora;
    int descuento
    DtComidaVendida comidaEnFactura;            
    string nroFactura;
    int subtotal;
    string nombreMozo;
public:
	Factura(int descuento, set<DtComidaVendida> sc, string nv, string nombre);
    
    //Geters
    DtFecha getFecha();
    DtHora getHora();
    int getDescuento();
    set<DtComidaVendida> getComidaEnFactura();            
    string getNroFactura();
    int getSubtotal();
    string getNombreMozo();
	int getTotal();
    //Posta
    DtFactura generarDtFactura();
}


#endif
