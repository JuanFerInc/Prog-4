#include "../Header/Mesa.h"

DtFactura Mesa::facturar(int descuento){
    set<DtComidaVendida>* setsito = linkVenta->darComidas();
    int subtotal = linkVenta->getSubtotal, num = linkVenta->getNroVenta;
    string nombre = linkMozo->getNombre; 
    
    Factura* fac = new Factura(descuento, setsito, num, subtotal);
    linkVenta->finalizarVenta(fac);
    
    DtFactura retorno = fac->generarDt()
    return retorno;
}
