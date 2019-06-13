
#include "../Header/DtFecha.h"

#include <iostream>

//Constructor
DtFecha::DtFecha() {

}

DtFecha::DtFecha(int di, int me, int an) {
	d = di;
	m = me;
	a = an;
}
DtFecha::DtFecha(const DtFecha& fecha) {
	this->d = fecha.d;
	this->m = fecha.m;
	this->a = fecha.a;
}
//getters
int DtFecha::getDia() {
	return d;
}

int DtFecha::getMes() {
	return m;
}

int DtFecha::getAnio() {
	return a;
}

//Otras
bool DtFecha::operator==(DtFecha fecha) {
	bool iguales = false;
	if ((this->d == fecha.d) && (this->m == fecha.m) && (this->a == fecha.a)) {
		iguales = true;
	}
	return iguales;
}
bool DtFecha::operator<(const DtFecha& fechita) {
	if (this->a < fechita.a) {
		return true;
	}
	else if (fechita.a < this->a) {
		return false;
	}
	else {
		if (this->m < fechita.m) {
			return true;
		}
		else if (fechita.m < this->m) {
			return false;
		}
		else {
			if (this->d < fechita.d) {
				return true;
			}
			else return false;
		}
	}
}

std::ostream& operator<<(std::ostream& out, DtFecha*info) {
	info->print(out);
	return out;
}

void DtFecha::print(std::ostream& out) {
	using namespace std;
	out << "dia: " << this->d << endl;
	out << "mes: " << this->m << endl;
	out << "anio: " << this->a << endl;
}
