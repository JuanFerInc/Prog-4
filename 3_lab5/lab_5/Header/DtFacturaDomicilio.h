#include "../Header/DtFactura.h"
class DtFacturaDomicilio : public DtFactura {
private:
	DtDelivery delivery;
public:
	DtDelivery getDelivery();

};
