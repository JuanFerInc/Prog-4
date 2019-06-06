#include "../Header/DtProducto.h"

DtProducto::DtProducto(const DtProducto& producto) {

}
DtProducto::DtProducto(string codigo, string descripcion, int precioTotal) :DtComida(codigo, descripcion, precioTotal) {

}