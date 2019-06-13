#include "../Header/DtProductoMenu.h"

DtProductoMenu::DtProductoMenu(const DtProductoMenu &dt) {
	this->cantidad = dt.cantidad;
	this->codigo = dt.codigo;
}



int DtProductoMenu::getCantidad() const {
	return this->cantidad;
}

DtProductoMenu::DtProductoMenu(string codigo, int cantidad) {
	this->cantidad = cantidad;
	this->codigo = codigo;

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
bool DtProductoMenu::operator<(const DtProductoMenu& d)const {
	if (this->codigo.compare(d.codigo) <= 0) {
		return true;
	}
	else {
		return false;
	}
}