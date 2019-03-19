#include <iostream>
#include <string>

#include "Header/bicicleta.h"
#include "Header/DtBicicleta.h"
#include "Header/DtFecha.h"
#include "Header/DtMonopatin.h"
#include "Header/DtVehiculo.h"
#include "Header/DtViaje.h"
#include "Header/DtViajesBase.h"
#include "Header/monopatin.h"
#include "Header/TipoBici.h"
#include "Header/usuario.h"
#include "Header/vehiculo.h"


#define MAX_VEHICULOS 30
#define MAX_USUARIOS 10


Usuario *Usuarios[MAX_USUARIOS];
Vehiculo *Vehiculos[MAX_VEHICULOS];




/*
Registra un Ususario en el sistema. La fecha de ingreso se obtiene del reloj de la máquina. Si
existe un usuario registrado con la misma cédula, se levanta una excepción
std::invalid_argument.
*/
void registrarUsuario(std::string ci, std::string nombre) {

	bool hay_lugar = false, no_registrado = true;
	int i = 0, lugar = 0;

	//falta ver como obtener fecha
	int dia = getdia();
	int mes = getmes();
	int anio = getanio();
	//cambiar como obtener fecha


	DtFecha fecha(dia, mes, anio);

	Usuario *nuevo_usuario = new Usuario(ci, nombre, fecha)



		while (i < MAX_USUARIOS && hay_lugar && no_registrado) {
			if (Usuarios[i] == NULL) {
				hay_lugar = true;
				lugar = i;

			}if (Usuarios[i]->getCedula() == ci) {
				no_registrado = false;
			}
			i++;
		}
	if (!no_registrado) {
		excepcion
	}
	else if (hay_lugar) {
		Usuarios[i] = *(nuevo_usuario);
	}
	else {
		std::cout << "sin lugar" << std::endl;

	}

}

/*
Agrega un nuevo vehículo al sistema.Controlar que se cumplen : (1) no existe un
vehículo con el mismo número de serie, (2) porcentaje como valor entre 0 y 100 y(3)
precio base positivo.De no ser así, se levanta una excepción std::invalid_argument.
*/
void agregarVehiculo(const DtVehiculo& vehiculo) {
	bool monopatin; //1 = monopatin
	DtVehiculo nuevo_vehiculo(vehiculo);


	if(!((0 <= nuevo_vehiculo.getporcentaje()) && (nuevo_vehiculo.getporcentaje <= 100) && (nuevo_vehiculo.getprecioBase > 0)) ){
		
	}
	else {

		bool hay_lugar = false, no_registrado = true;
		int i = 0, lugar = 0;
		while (i < MAX_VEHICULOS && hay_lugar && no_registrado) {
			if (Vehiculos[i] == NULL) {
				hay_lugar = true;
				lugar = i;

			}if (vehiculo.nroSerie == vehiculos[i]->getnroSerie()) {
				no_registrado = false;
			}
			i++;
		}
		if (!no_registrado) {
			excepcion
		}
		else if (hay_lugar) {
			Vehiculo* nuevo_vehiculo;
			if (monopatin) {
				DtMonopatin* nuevo_monopatin = vehiculo;
				nuevo_vehiculo = new Monopatin(nuevo_monopatin->getnroSerie(), nuevo_monopatin->getporcentaje(), nuevo_monopatin->getprecioBase(), nuevo_monopatin->gettieneLuces()); //puede ser puntero a monopatin
			}
			else {
				DtBicicleta* nueva_bicicleta
			}


			Vehiculo* nuevo_vehiculo = new Vehiculo();
			Vehiculos[i] = *(nuevo_vehiculo);
		}
		else {
			std::cout << "sin lugar" << std::endl;

		}


	}
}

/*
Crea un viaje entre el usuario y el vehículo identificados por ci y
nroSerieVehiculo, respectivamente. Controlar que se cumplen: (1) existe un
usuario registrado con esa ci, (2) existe un vehículo registrado con ese nro serie, (3)
duración y distancia positivas y (4) fecha del viaje posterior o igual a la fecha de
ingreso del usuario. De no ser así, se levanta una excepción std::invalid_argument.
*/
void ingresarViaje(std::string ci, int nroSerieVehiculo, const DtViajeBase& viaje) {

}
/*
Devuelve un arreglo con información detallada de los viajes realizados por el usuario
antes de cierta fecha. Para poder implementar esta operación se deberá sobrecargar el
operador < (menor que) del tipo de datos (data type) DtFecha. cantViajes es un
parámetro de salida donde se devuelve la cantidad de viajes encontrados (corresponde
a la cantidad de valores DtViaje que se devuelven).
*/
DtViaje** verViajesAntesDeFecha(const DtFecha& fecha, std::string ci, int &cantViajes) {

}

/*
Elimina los viajes del usuario identificado por ci, realizados en la fecha ingresada. Si
no existe un usuario registrado con esa cédula, se levanta una excepción
std::invalid_argument.
*/
void eliminarViajes(std::string ci, const DtFecha& fecha) {

}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por
nroSerieVehiculo. En caso de que el vehículo no exista, o la carga ingresada no se
encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {

}

/*
Devuelve un arreglo con los vehículos del sistema. cantVehiculos es un parámetro
de salida donde se devuelve la cantidad de vehículos (corresponde a la cantidad de
valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {

}

/*
Menu sencillo interactivo para poder probar 
las funcionalidades requeridas
*/
void menuSencillo() {

}

int main(){
	for (int i = 0; i < MAX_USUARIOS; i++)
		Usuario[i] = NULL;
	for (int i = 0; i < MAX_VEHICULOS; i++)
		Vehiculos[i] = NULL;


	std::cout << "COMPILO " << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}