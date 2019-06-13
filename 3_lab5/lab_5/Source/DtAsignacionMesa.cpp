#include "../Header/DtAsignacionMesa.h"
#include "../Header/DtMozo.h"
#include "../Header/DtAsignacionMesa.h"
#include <set>
#include <string>
//getters

DtMozo DtAsignacionMesa::getMozo() {
    return(this->mozo);
}
DtAsignacionMesa::DtAsignacionMesa(DtMozo mozo, set<int> nroMesas){
	this->mozo = mozo;
	this->mesasDelMozo = nroMesas;
}

DtAsignacionMesa::DtAsignacionMesa(const DtAsignacionMesa &dtasig) {
    this->mozo=dtasig.mozo;
    this->mesasDelMozo=dtasig.mesasDelMozo;
}

set<int> DtAsignacionMesa::getMesasDelMozo() {
    return (this->mesasDelMozo);
}

void DtAsignacionMesa::agregarMesa(int mesa) {
	mesasDelMozo.insert(mesa);
}

std::ostream& operator<<(std::ostream& out, DtAsignacionMesa*info) {
	info->print(out);
	return out;
}

void DtAsignacionMesa::print(std::ostream& out) {
	using namespace std;
	out << "Mozo: " << &this->mozo << endl;
	out << "Mesas de un Mozo: ";
	set<int>::iterator iter;
	for (iter = mesasDelMozo.begin(); iter != mesasDelMozo.end(); iter++) {
		out << " " << (*iter) << endl;
	}

}
bool DtAsignacionMesa::operator<(const DtAsignacionMesa& d) const {
	if (this->mozo.getNombre().compare(d.mozo.getNombre()) <= 0) {
		return true;
	}
	else {
		return false;
	}

}