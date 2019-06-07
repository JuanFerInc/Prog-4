#include "../Header/Producto.h"
#include "../Header/DtProducto.h"
#include "../Header/Comida.h"

#include <iostream>

using namespace std;
Comida::Comida(string codigo, string descripcion) {
	this->descripcion = descripcion;
	this->codigo = codigo;
	this->cantitatUnidadesFacturadas = 0;
}

void Comida::setDescripcion(string desc) {
	this->descripcion = desc;
}
void Comida::setCodigo(string codigo) {
	this->codigo = codigo;
}
string Comida::getCodigo() {
	return this->codigo;
}
string Comida::getDescripcion() {
	return this->descripcion;
}

bool Comida::sonIguales(string codigo) {
	return codigo == this->codigo;
}

void Comida::incrementarCantidadUnidadesVendidas(int jorge) {
	this->cantitatUnidadesFacturadas = this->cantitatUnidadesFacturadas + jorge;
}