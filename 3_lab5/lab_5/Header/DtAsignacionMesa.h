#ifndef DTASIGNACIONMESA_H
#define DTASIGNACIONMESA_H	

#include <set>
#include "../Header/DtMozo.h"

class DtAsignacionMesa {
private:
	DtMozo mozo;
	set<int> mesasDelMozo;

public:
	int getMozo();
	set<int> getMesasDelMozo();
};
#endif