#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <strings>

#include "../Header/IObserver.h"
#include "../Header/Factura.h"

#include "../Header/DtEstado.h"
#include "../Header/DtEmpleado.h"
#include "../Header/DtEmpleadoVendida"

using namespace std;

class Empleado  {
private:
    int numEmpleado;
    string nombre;
public:
    virtual string getNombre()=0;
    virtual int getnumEmpleado()=0;
    

}

class Dlivery: public Empleado{
private
    TipoDeTransporte TipoTransporte;
public:
    string getNombre();
    int getnumEmpleado();
}

class Mozo:public Empleado{
public:
    int* mesas;
public:
    int* getMesas()
    string getNombre();
    int getnumEmpleado();
    
}

#endif
