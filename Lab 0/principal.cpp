#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

#include "Header/bicicleta.h"
#include "Header/DtBicicleta.h"
#include "Header/DtFecha.h"
#include "Header/DtMonopatin.h"
#include "Header/DtVehiculo.h"
#include "Header/DtViaje.h"
#include "Header/DtViajeBase.h"
#include "Header/monopatin.h"
#include "Header/TipoBici.h"
#include "Header/usuario.h"
#include "Header/vehiculo.h"


#define MAX_VEHICULOS 30
#define MAX_USUARIOS 10


Usuario *Usuarios[MAX_USUARIOS];
Vehiculo *Vehiculos[MAX_VEHICULOS];




/*
Registra un Ususario en el sistema. La fecha de ingreso se obtiene del reloj de la m�quina. Si
existe un usuario registrado con la misma c�dula, se levanta una excepci�n
std::invalid_argument.
*/
void registrarUsuario(std::string ci, std::string nombre) {
	bool hay_lugar = false, no_registrado = true;
	int i = 0, lugar = 0;
	



	while (i < MAX_USUARIOS && no_registrado) {
		if (Usuarios[i] == NULL) {
			hay_lugar = true;
			lugar = i;
			}if (Usuarios[i]->getCedula() == ci) {
			no_registrado = false;
		}
		i++;
	}

	if (!no_registrado) {
		throw std::invalid_argument("Usuario Registrado");
	}else if (hay_lugar) {
		//Obtenemos tiempo de la computardora
		// se le suma 1 al mes
		// se le suma 1900 al anio
		time_t current_time = time(0);
		tm *t = localtime(&current_time);

		int dia = t->tm_mday;
		int mes = t->tm_mon + 1;
		int anio = t->tm_year + 1900;

		//creacion de la DtFecha
		DtFecha fecha(dia, mes, anio);

		Usuarios[lugar] = new Usuario(ci, nombre, fecha);

	}else {
		throw std::invalid_argument("El arreglo esta lleno");
	}
}

/*
Agrega un nuevo veh�culo al sistema.Controlar que se cumplen : (1) no existe un
veh�culo con el mismo n�mero de serie, (2) porcentaje como valor entre 0 y 100 y(3)
precio base positivo.De no ser as�, se levanta una excepci�n std::invalid_argument.
*/
void agregarVehiculo(const DtVehiculo& vehiculo) {

	const DtMonopatin *monopatin = dynamic_cast<const DtMonopatin*>(&vehiculo);
	const DtBicicleta *bicicleta = dynamic_cast<const DtBicicleta*>(&vehiculo);


	if(!((0 <= vehiculo.getporcentajeBateria()) && (vehiculo.getporcentajeBateria <= 100) )){
		throw std::invalid_argument("Porcentaje de bateria fuera de rango");
	}
	else if (!(vehiculo.getprecioBase > 0)) {
		throw std::invalid_argument("Precio base invalido");
	}else {
		bool hay_lugar = false, no_registrado = true;
		int i = 0, lugar = 0;

		while (i < MAX_VEHICULOS && no_registrado) {
			if (Vehiculos[i] == NULL) {
				hay_lugar = true;
				lugar = i;

			}else if (vehiculo.getnroSerie() == Vehiculos[i]->getnroSerie()) {
				no_registrado = false;
			}
			i++;
		}
		if (!no_registrado) {
			throw std::invalid_argument("Vehiculo ya existe");
		}
		else if (hay_lugar) {
			Vehiculo *nuevo_vehiculo;
			if (monopatin) {
				nuevo_vehiculo = new Monopatin(monopatin->getnroSerie(),monopatin->getporcentajeBateria() ,monopatin->getprecioBase(), monopatin->gettieneLuces());

			}
			else if (bicicleta) {
				nuevo_vehiculo = new Bicicleta(bicicleta->getnroSerie(), bicicleta->getporcentajeBateria(), bicicleta->getprecioBase(), bicicleta->getTipoBici(), bicicleta->getcantCambios());
			}
			Vehiculos[lugar] = nuevo_vehiculo;

		}
		else {
			throw std::invalid_argument("El arreglo esta lleno");

		}


	}
}

/*
Crea un viaje entre el usuario y el veh�culo identificados por ci y
nroSerieVehiculo, respectivamente. Controlar que se cumplen: (1) existe un
usuario registrado con esa ci, (2) existe un veh�culo registrado con ese nro serie, (3)
duraci�n y distancia positivas y (4) fecha del viaje posterior o igual a la fecha de
ingreso del usuario. De no ser as�, se levanta una excepci�n std::invalid_argument.
*/
void ingresarViaje(std::string ci, int nroSerieVehiculo, const DtViajeBase& viaje) {
	
}




static Usuario* conseguirUsuario(std::string ci){
	int i=0;

	while((i < MAX_USUARIOS) && (strcmp(ci, Usuarios[i]->getCedula()) != 0))
		i++;
	if(strcmp(ci, Usuarios[i]->getCedula()) == 0)){
		return Usuarios[i];
	}else{
		return NULL;
	}
    return NULL;
	
}

/*
Devuelve un arreglo con informaci�n detallada de los viajes realizados por el usuario
antes de cierta fecha. Para poder implementar esta operaci�n se deber� sobrecargar el
operador < (menor que) del tipo de datos (data type) DtFecha. cantViajes es un
par�metro de salida donde se devuelve la cantidad de viajes encontrados (corresponde
a la cantidad de valores DtViaje que se devuelven).
*/
DtViaje** verViajesAntesDeFecha(const DtFecha& fecha, std::string ci, int &cantViajes) {
	
	DtFecha fechita = DtFecha(fecha);
	cantViajes = 0;
	Usuario* p = conseguirUsuario(ci);
	if(p != NULL){
		cantViajes = p->contarViajes(fechita);
		DtViaje * res = p->arregloViajesMenores(fechita, cantViajes);

		
	}
	int j = 0;

	for(int i = 0; i < 100; i++){
		if( p->Viajes[i] != NULL){
				if(p->Viajes[i]->getfecha() < fechita){
					Vehiculo *m = p->Viajes[i]->getvehiculo();
					DtViaje *copia = new DtViaje(p->Viajes[i]->getfecha(), p->Viajes[i]->getduracion(), p->Viajes[i]->getdistancia(),, );
					res[j] = ;
				}
			}
	}
	return NULL;
}


/*
Elimina los viajes del usuario identificado por ci, realizados en la fecha ingresada. Si
no existe un usuario registrado con esa c�dula, se levanta una excepci�n
std::invalid_argument.
*/
void eliminarViajes(std::string ci, const DtFecha& fecha) {
	/*
	Usuario* p = conseguirUsuario(ci);

	}if(p == NULL){
		throw std::invalid_argument( "No hay usuario registrado con esa cedula" );
	}else{
		p->EliminarViaje(fecha);
	}
	*/
}

/*
Modifica el porcentaje de carga de la bateria del veh�culo identificado por
nroSerieVehiculo. En caso de que el veh�culo no exista, o la carga ingresada no se
encuentre entre 0 y 100 se levanta una excepci�n std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {
	/*
	int i = 0;
	bool esta = false;
	while ((i < 100) && (!esta)) {
		if (!(Vehiculos[i] == NULL) && (Vehiculos[i]->getnroSerie() == nroSerieVehiculo)) {
			esta = true;
			Vehiculos[i]->setporcentajeBateria(cargaVehiculo);
		}
		else {
			i++;
		}
	}
	if (!esta) {
		throw std::invalid_argument("No esta el vehiculo");
	}
	*/
}

/*
Devuelve un arreglo con los veh�culos del sistema. cantVehiculos es un par�metro
de salida donde se devuelve la cantidad de veh�culos (corresponde a la cantidad de
valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
	/*
	int j = 0;

	//contamos cantidad de vehiculos
	for (int i = 0; i < 100; i++) {
		if (!(Vehiculos[i] == NULL)) {
			j++;
		}
	}
	
	cantVehiculos = j;

	DtVehiculo **res = new DtVehiculo*[j];

	j = 0;

	for (int i = 0; i < 100; i++) {
		if (Vehiculos[i] != NULL) {
		

		}
	}
	*/
	return NULL;
}

/*
Menu sencillo interactivo para poder probar 
las funcionalidades requeridas
*/
void menuSencillo() {
	/*
	try {
	   bool salir = false;
	int comando;
	using namespace std;
	while(!salir){
		cout << "Bienvenido: presione uno de los siguientes comandos \n 1) Registrar usuario \n 2) Registrar Vehiculo \n 3) Ingresar Viaje \n 4) Ver viajes antes de una fecha \n 5) Eliminar Viajes antes de una fecha \n 6) Cambiar Bateria de un vehiculo \n 7) Obtener vehiculos \n";
		cin >> comando;
		if(comando == 1){
			cout << "Ingrese Nombre: " << endl;
			string ci, nombre;
			cin >> nombre
			cout << "Ingrese Cedula: " << endl;
			cin >> ci
			RegistrarUsuario(ci, nombre);
		}else if(comando == 2){
			int nroSerie;
			float porcentaje, precio;
			cout << "Ingrese nro de serie: " << endl;
			cin >> nroSerie;
			cout << "Ingrese porcentaje de bateria: " << endl;
			cin >> porcentaje;
			cout << "Ingrese precio base: " << endl;
			cin >> precio;
			const DtVehiculo vehiculo = new	DtVehiculo(nroSerie , porcentaje, precio);
			agregarVehiculo(vehiculo);
		}else if(comando == 3){
			sring ci;
			int nroSerieVehiculo, di, me, an, duracion_arg, distancia_arg;
			 cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese nro de serie del vehiculo: " << endl;
			cin >> nroSerieVehiculo;
			cout << "Ingrese dia: " << endl;
			cin >> di;
			cout << "Ingrese mes: " << endl;
			cin >> me;
			cout << "Ingrese anio: " << endl;
			cin >> an;
			cout << "Ingrese duracion: " << endl;
			cin >> duracion_arg;
			cout << "Ingrese distancia recorrida: " << endl;
			cin distancia_arg;
			DtFecha* fecha_arg = new DtFecha(di, me, an);
			const DtViajeBase* viaje = new DtViajeBase(fecha_arg, int duracion_arg, int distancia_arg);
			ingresarViaje(ci, nroSerieVehiculo, const DtViajeBase& viaje);
		}else if(comando == 4){
			int di, m, an, cantViajes = 0;
			string ci;
			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese dia: " << endl;
			cin >> di;
			cout << "Ingrese mes: " << endl;
			cin >> me;
			cout << "Ingrese anio: " << endl;
			cin >> an;
			const DtFecha* fecha_arg = new DtFecha(di, me, an);
			DtViaje** viajes_antes = verViajesAntesDeFecha(fecha_arg, std::string ci, int cantViajes);
			cout >> "Hizo "
			cout << "El usuario de CI " << ci << " hizo " << cantViajes << " viajes." << endl
		}else if(comando == 6){
			int nroSerieVehiculo;
			float cargaVehiculo;
			cout << "Ingrese nro de serie de vehiculo";
			cin >> nroSerieVehiculo;
			cout << "Ingrese nueva carga del vehiculo";
			cin >> cargaVehiculo;
			try{
				cambiarBateriaVehiculo(nroSerieVehiculo, cargaVehiculo);
			}catch(exception& e){          //Hay que discernir en casos????
				cout << "Por favor coloque par�metros correctos" << endl;
			}
		}else if(comando == 7){

		}else{
			cout << "Comando no reconocido, intente nuevamente" << endl;
		}
	}
	}
	catch (const std::exception &invalid_argument) {

	}
	*/
}

int main(){
	for (int i = 0; i < MAX_USUARIOS; i++)
		Usuarios[i] = NULL;
	for (int i = 0; i < MAX_VEHICULOS; i++)
		Vehiculos[i] = NULL;


	DtVehiculo *autos = &DtMonopatin(1, 10, 10,1);
	
	
	//std::cout<< m->gettieneLuces()<<std::endl;
	agregarVehiculo(*autos);


	std::cout << "COMPILO " << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}