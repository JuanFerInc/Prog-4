#include "../Header/DtFactura.h"
#include "../Header/DtMozo.h"

class DtFacturaLocal : public DtFactura {
private:
	DtMozo mozo;
public:
	DtMozo getMozo();

};
