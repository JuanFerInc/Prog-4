#include "../Header/DtFactura.h"
#include "../Header/DtDelivery.h"

class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtDelivery getDelivery();

};
