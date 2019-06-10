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
	void agregar(IObserver* observer);
	void eliminar(IObserver* observer);
	void cancelarPedido();
	void siguienteEstado();
	DtEstadoTerminado darDatatypeTermnado(DtEstado estado);
	Factura* crearFactura(int descuento);
	DtDelivery darDtDelivery();

};
