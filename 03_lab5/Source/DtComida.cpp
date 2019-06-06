#include <iostream>
#include "../Header/DtComida.h"
#include "../Header/Comida.h"

using namespace std;

DtComida::DtComida(string codigo, string descripcion, int precioTotal) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->precioTotal = precioTotal;

}
DtProducto::DtProducto(const DtProducto& producto) {

}
DtProducto::DtProducto(string codigo, string descripcion, int precioTotal) :DtComida(codigo, descripcion, precioTotal) {
	
}

DtMenu::DtMenu(string codigo, string descripcion, int precioTotal, set<DtProductoVenta>datosProductos) : DtComida(codigo, descripcion, precioTotal) {
	this->productosDeMenu = datosProductos;
}

DtProductoVenta::DtProductoVenta(DtProducto producto, int cantidad) : DtProducto(producto, cantidad)) {
	this->cantidad = cantidad;

}