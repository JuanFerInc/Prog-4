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
	int descuento;
    set<DtComida> comidaEnFactura;            
    string nroFactura;
    int subtotal;
public:
	Factura(int descuento, set<DtComidaVendida> sc, string nv);
    
    //Geters
    DtFecha getFecha();
    DtHora getHora();
    int getDescuento();
    set<DtComida> getComidaEnFactura();            
    string getNroFactura();
    int getSubtotal();
    string getNombreMozo();
	int getTotal();
    //Posta
    DtFactura generarDtFactura();
}


#endif
