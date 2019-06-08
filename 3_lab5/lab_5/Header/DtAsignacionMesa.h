#ifndef DTASIGNACIONMESA_H
#define DTASIGNACIONMESA_H	


#include "../Header/DtMozo.h"
#include <set>

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
	void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, DtAsignacionMesa*info);
};
#endif