#ifndef DTASIGNACIONMESA_H
#define DTASIGNACIONMESA_H	

#include <set>
#include "../Header/DtMozo.h"

class DtAsignacionMesa {
private:
	DtMozo mozo;
	set<int> mesasDelMozo;

public:
	//constructor por copia
	DtAsignacionMesa(const DtAsignacionMesa &dtasig);
	//geters
	DtMozo getMozo();
	set<int> getMesasDelMozo();

};
#endif