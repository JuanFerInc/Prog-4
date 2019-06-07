#include "../header/DtComidaVendida.h"

//getters

String DtComidaVendida::getNombre() {
    return(this->nombre);
}

int DtComidaVendida::getPrecio() {
    return (this->precio);
}

int DtComidaVendida::getPrecioTotal() {
    int c=this->precio()*this->cantidad();
    return (c);
}

int DtComidaVendida::getCantidad() {
    return(this->cantidad);
}

DtComidaVendida::DtComidaVendida(int cantidad, string descripcion, int precioTotalCalculable, string precio) {
    this->nombre=descripcion;
    this->precio=precio;
    this->precioTotal=precioTotalCalculable;
    this->cantidad=cantidad;
} 

DtComidaVendida::DtComidaVendida(const DtComidaVendida& dcv) {
    this->nombre=dcv.nombre;
    this->precio=dcv.precio;
    this->precioTotal=dcv.precioTotal;
    this->cantidad=dcv.cantidad;
}

void DtComidaVendida::print(std::ostream& out) {
    using namespace std;
    out << "Descripcion: " << this->getNombre() << endl;
    out << "Precio: " << this->getPrecio() <<endl;
    out << "PrecioTotal: " << this->getPrecioTotal() << endl;
    out << "cantidad: " << this->getCantidad() << endl;
}