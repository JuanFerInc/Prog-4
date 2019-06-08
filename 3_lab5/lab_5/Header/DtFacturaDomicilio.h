#ifndef DTFACTURADOMICILIO_H
#define DTFACTURADOMICILIO_H

#include "../Header/DtFactura.h"
#include "../Header/DtDelivery.h"

class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtDelivery getDelivery();
	void print(std::ostream& out);

};

#endif