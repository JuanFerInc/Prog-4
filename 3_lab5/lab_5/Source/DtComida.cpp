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

std::ostream& operator<<(std::ostream& out, DtComida*info) {
	info->print(out);
	return out;
}

void DtComida::print(std::ostream& out) {
	using namespace std;
	out << "Codigo: " << this->codigo << endl;
	out << "descripcion: " << this->descripcion << endl;
	out << "precio total " << this->precioTotal << endl;
}
bool DtComida::operator<(const DtComida& d)const {
	if (this->codigo.compare(d.codigo) <= 0) {
		return true;
	}
	else {
		return false;
	}
}