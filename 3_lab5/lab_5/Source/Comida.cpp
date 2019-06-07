#include "../Header/Producto.h"
#include "../Header/DtProducto.h"
#include "../Header/Comida.h"

#include <iostream>

using namespace std;

bool Comida::sonIguales(string codigo) {
	return codigo == this->codigo;
}
