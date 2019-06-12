#ifndef FACTURA_H
#define FACTURA_H


#include <iostream>
#include <set>


#include "../Header/DtFecha.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"
#include "../Header/DtFacturaLocal.h"
#include "../Header/DtFacturaDomicilio.h"

class Factura {
private:
    DtFecha fecha;
    DtHora hora;
	int descuento;
    set<DtComidaVendida> comidaEnFactura;    //LA IMPRESION HAY QUE REVISAR        
    string nroFactura;
    float subtotal;

public:
	Factura(int descuento, set<DtComidaVendida> comidaEnFactura, string nroFactura , float subtotal);
    
    //Geters
	DtFecha getFecha();
	DtHora getHora();
	int getDescuento();
	set<DtComidaVendida> getComidaEnFactura();
	string getNroFactura();
	float getSubtotal();
	float getMontoTotal();
    //Posta
    DtFacturaLocal *generarDtFacturaLocal(DtMozo dt);

	//Venta a Domicilio
	DtFacturaDomicilio *darDtFacturaDomicilio(DtDelivery dt);
	DtFactura *darDtFacturaDomicilioSinDelivery();
};

#endif
