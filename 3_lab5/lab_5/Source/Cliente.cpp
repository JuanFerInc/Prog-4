#include "../Header/Cliente.h"

//setters
void Cliente::setTelefono(string tel) {
    this->telefono = tel;
}

void Cliente::setDireccion(DtDireccion dir) {
    this->direccion = dir;
}

//getters

string Cliente::getTelefono() {
    return (this->telefono);
}

DtDireccion Cliente::getDireccion() {
    return (this->direccion);
}

set<DtEstadoTerminado> Cliente::getActualizaciones() {
    return (this->actualizaciones);
}

//otras

void Cliente::notificar(DtEstadoTerminado data) {
    this->actualizaciones.insert(data);
}



