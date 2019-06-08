#include "../Header/DtProductoMenu.h"
#include <string>

DtProductoMenu::DtProductoMenu(const DtProductoMenu &dt) {
	this->cantidad = dt.cantidad;
	this->codigo = dt.codigo;
}

int DtProductoMenu::getCantidad() const {
	return this->cantidad;
}

string DtProductoMenu::getCodigo() const {
	return this->codigo;
}

std::ostream& operator<<(std::ostream& out, DtProductoMenu*info) {
	info->print(out);
	return out;
}
void DtProductoMenu::print(std::ostream& out) {
	using namespace std;
	out << "codigo: " << this->codigo << endl;
	out << "cantidad: " << this->cantidad << endl;

}