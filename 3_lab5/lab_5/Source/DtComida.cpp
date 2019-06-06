#include <iostream>
#include "../Header/DtComida.h"


using namespace std;

DtComida::DtComida(string codigo, string descripcion, int precioTotal) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->precioTotal = precioTotal;

}
