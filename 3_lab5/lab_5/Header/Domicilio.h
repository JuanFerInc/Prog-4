#include "../Header/Venta.h"

class Domicilio : public Venta {
private:
	IObserver* linkIObserver;
	Cliente* linkCliente;
	Estado* linkEstado;
public:
	void agregar(IObserver observer);
	void eliminar(IObserver observer);
	void cancelarPedido();
	void siguienteEstado();
	DtEstadoTerminado darDatatypeTermnado(DtEstado estado);

};
