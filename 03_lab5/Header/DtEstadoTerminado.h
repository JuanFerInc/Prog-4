#include "../Header/DtEstado.h"
class DtEstadoTerminado : public DtEstado {
private:
	string nombre, telefono;
	DtHora hora;
	set<DtComidaVendida> comidasVendidas;

public:
	string getNombre();
	string getTelefono();
	DtHora getHora();
	set<DtComidaVendida> getComidasVendidas();


};