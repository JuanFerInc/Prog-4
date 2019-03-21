#include <string>
#include "../Header/DtViaje.h"



DtViaje::DtViaje(){
}
DtViaje::DtViaje(DtFecha fecha_arg, int duracion_arg, int distancia_arg, float precioTotal_arg, DtVehiculo vehiculo_arg):DtViajeBase(fecha_arg,duracion_arg,distancia_arg) {
	precioTotal = precioTotal_arg;
	vehiculo = vehiculo_arg;
}

bool DtViaje::sonIguales(DtViaje* a_comparar) {		//Preguntar lo de puntero
	if ((a_comparar->getFecha() == this->getFecha()) && (a_comparar->getDuracion() == this->getDuracion()) && (a_comparar->getDistancia() == this->getDistancia())) {
		return true;
	}
	else {
		return false;
	}
}

