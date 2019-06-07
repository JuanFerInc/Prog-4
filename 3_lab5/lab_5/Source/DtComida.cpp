#include <iostream>
#include <string>
#include "../Header/DtComida.h"


using namespace std;

//geters
string DtComida::getCodigo() const{
	return this->codigo;
}

string DtComida::getDescripcion() const{
	return this->descripcion;
}

int DtComida::getPrecioTotal() const{
	return this->precioTotal;
}
//Constructor por copia
DtComida::DtComida(const DtComida &comida) {
	this->codigo = comida.codigo;
	this->descripcion = comida.descripcion;
	this->precioTotal = comida.precioTotal;
}

DtComida::DtComida(string codigo, string descripcion, int precioTotal) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->precioTotal = precioTotal;

}
