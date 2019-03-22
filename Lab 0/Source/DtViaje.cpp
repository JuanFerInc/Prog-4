#include <string>
#include "../Header/DtViaje.h"



DtViaje::DtViaje(){
}
DtViaje::DtViaje(DtFecha fecha_arg, int duracion_arg, int distancia_arg, float precioTotal_arg, DtVehiculo vehiculo_arg):DtViajeBase(fecha_arg,duracion_arg,distancia_arg) {
	precioTotal = precioTotal_arg;
	vehiculo = vehiculo_arg;
}



float DtViaje::getprecioTotal(){
    return this->precioTotal;
}
DtVehiculo DtViaje::getvehiculo(){
    return this->vehiculo;
}
