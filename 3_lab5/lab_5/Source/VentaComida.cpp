#include "../Header/VentaComida.h"

bool VentaComida::tieneMismo(string codigo) {
	return this->linkComida->sonIguales(codigo);
}