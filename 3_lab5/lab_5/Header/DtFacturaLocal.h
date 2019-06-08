#ifndef DTFACTURALOCAL_H
#define DTFACTURALOCAL_H

#include "../Header/DtFactura.h"
#include "../Header/DtMozo.h"

class DtFacturaLocal : public DtFactura {
private:
	DtMozo mozo;
public:
	DtMozo getMozo();
	void print(std::ostream& out);

};

#endif