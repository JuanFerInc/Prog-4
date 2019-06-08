#include "../Header/DtEstado.h"
#include <string>

DtEstado::DtEstado(const DtEstado &e){
	this->etapaActual = e.etapaActual;
}

DtEstado::DtEstado(string c) {
	this->etapaActual = c;
}

string DtEstado::getEtapaActual() const{
	return this->etapaActual;
}

std::ostream& operator<<(std::ostream& out, DtEstado*info) {
	info->print(out);
	return out;
}

void DtEstado::print(std::ostream& out) {
	using namespace std;
	out << "Etapa Actual: " << this->etapaActual << endl;

}
