#ifndef IEMPLEADOS
#define IEMPLEADOS_H

#include <iostream>
#include <set>


#include "../Header/DtAsignacionMesa.h"
#include "../Header/Delivery.h"



using namespace std;


class IEmpleado {
public:
    //Alta empleado
	virtual set<int> mesasDeMozo(int nroEmpleado) = 0;
	virtual void elegirVehiculo(TipoTransporte vehiculo)=0;
	virtual void cancelarEmpleado()=0;
	virtual void confirmarEmpleado()=0;
	virtual void agregarMozo(string nombre)=0;
	virtual set<TipoTransporte> agregarDelivery(string nombre)=0;

    
    //Asignar automaticamente mozos a mesas
    virtual set<DtAsignacionMesa> asignarAuto() = 0;
    
    //Venta a domicilio
	virtual void seleccionarRepartidor(string nroEmpleado) = 0;
	virtual set<DtDelivery*> darRepartidores() = 0;
	virtual Delivery* pedirDelivery() = 0;

    
    
};

#endif


