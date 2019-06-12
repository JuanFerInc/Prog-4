#ifndef DTESTADOTERMINADO_H
#define DTESTADOTERMINADO_H


#include "../Header/DtEstado.h"
#include "../Header/DtHora.h"
#include "../Header/DtComidaVendida.h"


using namespace std;

class DtEstadoTerminado : public DtEstado {
private:
	string nombre, telefono;
	DtHora hora;
	set<DtComidaVendida*> comidasVendidas;

public:
	DtEstadoTerminado(string nombre, string telefono, DtHora hora, string etapa, set<DtComidaVendida*> comidasVendidas);
	//Constructor por copia
	DtEstadoTerminado(const DtEstadoTerminado &dtterm);
	//geters
	string getNombre();
	string getTelefono();
	DtHora getHora();
	set<DtComidaVendida*> getComidasVendidas();
	bool operator<(const DtEstadoTerminado& d)const;
	//impresion
	void print(ostream& out);


};
#endif // !DTESTADOTERMINADO_H