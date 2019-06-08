#include "../Header/Venta.h"
#include "../Header/IObserver.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"


class Domicilio : public Venta {
private:
	IObserver* linkIObserver;
	Cliente* linkCliente;
	Estado* linkEstado;
public:
	Domicilio(Cliente*, Estado*);
	void agregar(IObserver observer);
	void eliminar(IObserver observer);
	void cancelarPedido();
	void siguienteEstado();
	DtEstadoTerminado darDatatypeTermnado(DtEstado estado);

};
