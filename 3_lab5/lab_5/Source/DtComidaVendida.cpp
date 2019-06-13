#include "../Header/DtComidaVendida.h"

//getters

string DtComidaVendida::getNombre() {
    return(this->nombre);
}

int DtComidaVendida::getPrecio() {
    return (this->precio);
}

int DtComidaVendida::getPrecioTotal() {
    int c= this->precio*this->cantidad;
    return (c);
}

int DtComidaVendida::getCantidad() {
    return(this->cantidad);
}

DtComidaVendida::DtComidaVendida(int cantidad, string descripcion, int precio) {
    this->nombre=descripcion;
    this->precio=precio;
    this->cantidad=cantidad;
} 

DtComidaVendida::DtComidaVendida(const DtComidaVendida& dcv) {
    this->nombre=dcv.nombre;
    this->precio=dcv.precio;
    this->cantidad=dcv.cantidad;
}

std::ostream& operator<<(std::ostream& out, DtComidaVendida*info) {
	info->print(out);
	return out;
}

void DtComidaVendida::print(std::ostream& out) {
	using namespace std;
	out << "Descripcion: " << this->nombre << endl;
	out << "Precio: " << this->precio << endl;
	out << "PrecioTotal: " << this->getPrecioTotal() << endl;
	out << "cantidad: " << this->cantidad << endl;
}
bool DtComidaVendida::operator<(const DtComidaVendida& d)const {
	if (this->nombre.compare(d.nombre) <= 0) {
		return true;
	}
	else {
		return false;
	}
}
