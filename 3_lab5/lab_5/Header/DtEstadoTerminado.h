#include "../Header/DtEstado.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"

using namespace std;

class DtEstadoTerminado : public DtEstado {
private:
	string nombre, telefono;
	DtHora hora;
	set<DtComidaVendida> comidasVendidas;

public:
	//Constructor por copia
	DtEstadoTerminado(const DtEstadoTerminado &dtterm);
	//geters
	string getNombre();
	string getTelefono();
	DtHora getHora();
	set<DtComidaVendida> getComidasVendidas();
	//impresion
	void print(ostream& out);


};