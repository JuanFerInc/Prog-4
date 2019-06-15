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
	DtAsignacionMesa(DtMozo mozo, set<int> nroMesas);
	DtAsignacionMesa(const DtAsignacionMesa &dtasig);
	//geters
	DtMozo getMozo() const;
	void agregarMesa(int mesa);
	set<int> getMesasDelMozo();
	void print(std::ostream& out);
	friend std::ostream& operator<<(std::ostream& out, DtAsignacionMesa *info);
	bool operator<(const DtAsignacionMesa& d)const;
};
#endif