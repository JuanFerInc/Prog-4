#ifndef DTDELIVERY_H
#define DTDELIVERY_H



#include "../Header/DtEmpleado.h"
#include "../Header/TipoTransporte.h"

class DtDelivery : public DtEmpleado {
private:
	string nombre;
	TipoTransporte transporte;
public:
	DtDelivery() = default;
	DtDelivery(string nombre, int nroEmpleado, TipoTransporte tipo);
	DtDelivery(const DtDelivery& a);
	//geters
	TipoTransporte getTransporte() const;
	bool operator<(const DtDelivery& d)const;
	
	void print(ostream& out);
};

#endif // !DTDELIVERY_H