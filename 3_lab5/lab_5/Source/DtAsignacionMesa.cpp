#include "../header/DtAsignacionMesa.h"
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

std::ostream& operator<<(std::ostream& out, DtAsignacionMesa*info) {
	info->print(out);
	return out;
}
void DtAsignacionMesa::agregarMesa(int mesa) {
	mesasDelMozo.insert(mesa);
}
void DtAsignacionMesa::print(std::ostream& out) {
	using namespace std;
	out << "Mozo: " << this->getMozo() << endl;
	out << "Mesas de un Mozo: ";
	for()

}