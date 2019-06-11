#include "../Header/Venta.h"
#include "../Header/IObserver.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"


class Domicilio : public Venta {
private:
	IObserver* linkIObserver;
	Cliente* linkCliente;
	Estado* linkEstado;
	Delivery* linkDelivery;
public:
	Domicilio(Cliente* cliente, Estado* estado, string nroVenta, set<VentaComida*> comidaContenida, int subtotal, Delivery* delivery);
	void cancelarPedido();
	void siguienteEstado();
	DtEstadoTerminado darDatatypeTerminado(DtEstado estado);
	Factura* crearFactura(int descuento);
	DtDelivery darDtDelivery();

};
