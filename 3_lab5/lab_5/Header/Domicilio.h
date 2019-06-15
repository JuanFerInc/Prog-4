#ifndef DOMICILIO_H
#define DOMICILIO_H


#include "../Header/Venta.h"
#include "../Header/Delivery.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"
#include "../Header/Factura.h"
#include "../Header/VentaComida.h"


class Domicilio : public Venta {
private:
	IObserver* linkIObserver;
	Cliente* linkCliente;
	Estado* linkEstado;
	Delivery* linkDelivery;
public:
	Domicilio(Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery);
	Domicilio(DtHora horita, Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery);
	void cancelarPedido();
	void siguienteEstado();
	void siguienteEstado(DtHora horita);
	DtEstadoTerminado darDatatypeTerminado(DtEstado estado);
	DtEstadoTerminado darDatatypeTerminado(DtEstado estado,DtHora horita);
	Factura* crearFactura(int descuento);
	DtDelivery* darDtDelivery();
	bool tieneDelivery();
	
	~Domicilio() {};

};

#endif