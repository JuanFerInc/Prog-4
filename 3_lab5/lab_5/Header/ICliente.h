#ifndef ICLIENTE_H
#define ICLIENTE_H

#include <iostream>

#include "../Header/DtEstadoTerminado.h"
using namespace std;

class ICliente{
    public:
        virtual set<DtEstadoTerminado> verActualizacion(string tel) =0;
		virtual set<set<DtEstadoTerminado>> verTodasActualizaciones() = 0;
		virtual  DtCliente agregarCliente(string telefono, string nombre, DtDireccion dirrecion) = 0;
		virtual void aceptarCliente() = 0;
		virtual void cancelarCliente() = 0;

};

#endif


