#include "../Header/Producto.h"
#include "../Header/DtProducto.h"

#include <iostream>

using namespace std;

DtProducto Producto::darDataType() {
	DtProducto data(this->getCodigo(), this->getDescripcion(), this->getPrecio());
	return data;
}

bool Comida::sonIguales(string codigo) {
	return codigo == this->codigo;
}