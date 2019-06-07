#include "../header/DtAsignacionMesa.h"

//getters

DtMozo DtAsignacionMesa::getMozo() {
    return(this->mozo);
}

DtAsignacionMesa::DtAsignacionMesa(const DtAsignacionMesa &dtasig) {
    this->mozo=dtasig.mozo;
    this->mesasDelMozo=dtasig.mesasDelMozo;
}

set<int> DtAsignacionMesa::getMesasDelMozo() {
    return (this->mesasDelMozo);
}
