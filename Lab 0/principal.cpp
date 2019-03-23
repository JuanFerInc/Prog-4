#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

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
#define MAX_USUARIOS 3


Usuario *Usuarios[MAX_USUARIOS];
Vehiculo *Vehiculos[MAX_VEHICULOS];


//Devuelve un puntero al Usuario con ci o NULL si no existe
static Usuario* existeUsuario(std::string ci){
	Usuario* res = NULL;
	//bool parar = false;          //Esto no sería con while?
	for (int i = 0; i < MAX_USUARIOS; i++) {
		if ((Usuarios[i] != NULL) && (Usuarios[i]->getCedula() == ci)) {
			res = Usuarios[i];
		}
	}
	return res;
}
//Devuelve un puntero al vehiculo con nroSerieVehiculo o NULL si no existe
static Vehiculo* existeVehiculo(int nroSerieVehiculo) {
	Vehiculo* res = NULL;
	for (int i = 0; i < MAX_VEHICULOS; i++) {
		if ((Vehiculos[i] != NULL) && (Vehiculos[i]->getnroSerie() == nroSerieVehiculo)) {
			res = Vehiculos[i];
		}
	}
	return res;
}
//Devuelve true si y solo si la duracion > 0
static bool duracionValida(DtViajeBase via) {
	return (via.getDuracion() > 0);
}
//Devuelve true si y solo si la distancia > 0
static bool distanciaValida(DtViajeBase via) {
	return (via.getDistancia() > 0);
}

/*
Registra un Ususario en el sistema. La fecha de ingreso se obtiene del reloj de la máquina. Si
existe un usuario registrado con la misma cédula, se levanta una excepción
std::invalid_argument.
*/
void registrarUsuario(std::string ci, std::string nombre) {
	bool hay_lugar = false, no_registrado = true;
	int i = 0, lugar = 0;

	while (i < MAX_USUARIOS && no_registrado) {
		if (Usuarios[i] == NULL) {
			hay_lugar = true;
			lugar = i;
			
		}else {
			if (Usuarios[i]->getCedula() == ci) {
				no_registrado = false;
			}
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
Agrega un nuevo vehículo al sistema.Controlar que se cumplen : (1) no existe un
vehículo con el mismo número de serie, (2) porcentaje como valor entre 0 y 100 y(3)
precio base positivo.De no ser así, se levanta una excepción std::invalid_argument.
*/
void agregarVehiculo(const DtVehiculo& vehiculo) {

	const DtMonopatin *monopatin = dynamic_cast<const DtMonopatin*>(&vehiculo);
	const DtBicicleta *bicicleta = dynamic_cast<const DtBicicleta*>(&vehiculo);


	if(!((0 <= vehiculo.getporcentajeBateria()) && (vehiculo.getporcentajeBateria() <= 100) )){
		throw std::invalid_argument("Porcentaje de bateria fuera de rango");
	}
	else if (!(vehiculo.getprecioBase() > 0)) {
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
			Vehiculo *nuevo_vehiculo = NULL;
			if (monopatin != NULL) {                 //Agregue el != NULL
				nuevo_vehiculo = new Monopatin(monopatin->getnroSerie(),monopatin->getporcentajeBateria() ,monopatin->getprecioBase(), monopatin->gettieneLuces());

			}
			else if (bicicleta != NULL) {
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
Crea un viaje entre el usuario y el vehículo identificados por ci y
nroSerieVehiculo, respectivamente. Controlar que se cumplen: (1) existe un
usuario registrado con esa ci, (2) existe un vehículo registrado con ese nro serie, (3)
duración y distancia positivas y (4) fecha del viaje posterior o igual a la fecha de
ingreso del usuario. De no ser así, se levanta una excepción std::invalid_argument.
*/
void ingresarViaje(std::string ci, int nroSerieVehiculo, const DtViajeBase& viaje) {
	DtViajeBase via = DtViajeBase(viaje);
	Usuario* usu = existeUsuario(ci);
	Vehiculo* vehiculo = existeVehiculo(nroSerieVehiculo);
	if (usu == NULL) {
		throw std::invalid_argument("No existe usuario");
	}
	else {
		if (vehiculo == NULL) {
			throw std::invalid_argument("No existe vehiculo");
		}
		else {
			if (!duracionValida(via)){
				throw std::invalid_argument("Duracion Invalida");
			}
			else {
				if (!distanciaValida(via)) {
					throw std::invalid_argument("Distancia Invalida");
				}
				else {
					if (via.getFecha() < usu->getFechaIngreso()) {
						throw std::invalid_argument("Fecha Invalida");
					}
					else {
						Viaje *viajecito = new Viaje(via.getFecha(), via.getDistancia(), via.getDuracion(), vehiculo);
						usu->agregarViaje(viajecito);
					}
				}
			}	
		}
	}
}

/*
Devuelve un arreglo con información detallada de los viajes realizados por el usuario
antes de cierta fecha. Para poder implementar esta operación se deberá sobrecargar el
operador < (menor que) del tipo de datos (data type) DtFecha. cantViajes es un
parámetro de salida donde se devuelve la cantidad de viajes encontrados (corresponde
a la cantidad de valores DtViaje que se devuelven).
*/
DtViaje** verViajesAntesDeFecha(const DtFecha& fecha, std::string ci, int &cantViajes) {
	DtViaje ** res = NULL;
	DtFecha fechita = DtFecha(fecha);
	Viaje **Viajes = NULL;

	Usuario* p = existeUsuario(ci);
	if(p != NULL){
		cantViajes = p->contarViajes(fechita);
	}


	if (cantViajes > 0) {
		Viajes = p->arregloViajesMenores(fechita, cantViajes);
		res = new DtViaje*[cantViajes];
		
		for (int i = 0; i < cantViajes; i++) {

			DtVehiculo *data_vehiculo;

			Vehiculo *vehiculo = Viajes[i]->getviajaen();
			Monopatin *monopatin = dynamic_cast<Monopatin*>(vehiculo);
			Bicicleta *bicicleta = dynamic_cast<Bicicleta*>(vehiculo);
			
			if (monopatin) {

				data_vehiculo =  new DtMonopatin(monopatin->getnroSerie(), monopatin->getporcentajeBateria(), monopatin->getprecioBase(), monopatin->gettieneLuces());


			}
			else if (bicicleta) {
				data_vehiculo =  new DtBicicleta(bicicleta->getnroSerie(), bicicleta->getporcentajeBateria(), bicicleta->getprecioBase(), bicicleta->getTipo(), bicicleta->getcantCambios());
			}
			else {
				throw std::exception("No se pudo convertir de Vehiculo a una de sus clases derivadas");
			}
			DtViaje *data_viaje = new DtViaje(Viajes[i]->getfecha(), Viajes[i]->getduracion(), Viajes[i]->getdistancia(), Viajes[i]->getPrecioViaje(), data_vehiculo);
			res[i] = data_viaje;

		}
	}


	return res;
}


/*
Elimina los viajes del usuario identificado por ci, realizados en la fecha ingresada. Si
no existe un usuario registrado con esa cédula, se levanta una excepción
std::invalid_argument.
*/
void eliminarViajes(std::string ci, const DtFecha& fecha) {
	Usuario* p = existeUsuario(ci);

	if(p == NULL){
		throw std::invalid_argument( "No hay usuario registrado con esa cedula" );
	}else{
		p->eliminarViaje(fecha);
	}
}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por
nroSerieVehiculo. En caso de que el vehículo no exista, o la carga ingresada no se
encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {
	//int i = 0;
	Vehiculo *vehiculo = existeVehiculo(nroSerieVehiculo);

	if ((cargaVehiculo < 0) || (cargaVehiculo > 100)) {
		throw std::invalid_argument("Carga de fuera de rango");
	}
	else if (vehiculo == NULL) {
		throw std::invalid_argument("No esta el vehiculo");
	}else{
		vehiculo->setporcentajeBateria(cargaVehiculo);
	}
}

/*
Devuelve un arreglo con los vehículos del sistema. cantVehiculos es un parámetro
de salida donde se devuelve la cantidad de vehículos (corresponde a la cantidad de
valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
	
	int j = 0;

	//contamos cantidad de vehiculos
	for (int i = 0; i < MAX_VEHICULOS; i++) {
		if (!(Vehiculos[i] == NULL)) {
			j++;
		}
	}
	
	cantVehiculos = j;
	DtVehiculo **res = NULL;
	if (j > 0) {
		res = new DtVehiculo*[j];

		j = 0;

		for (int i = 0; i < MAX_VEHICULOS; i++) {
			if (Vehiculos[i] != NULL) {
				Bicicleta *bici = dynamic_cast<Bicicleta*>(Vehiculos[i]);
				Monopatin *monopatin = dynamic_cast<Monopatin*>(Vehiculos[i]);

				if (bici != NULL) {
					res[j] = new DtBicicleta(bici->getnroSerie(), bici->getporcentajeBateria(), bici->getprecioBase(), bici->getTipo(), bici->getcantCambios());
					j++;
				}
				else {//monopatin
					res[j] = new DtMonopatin(monopatin->getnroSerie(), monopatin->getporcentajeBateria(), monopatin->getprecioBase(), monopatin->gettieneLuces());
					j++;
				}
			}
		}
	}
	
	return res;
}

/*
Menu sencillo interactivo para poder probar 
las funcionalidades requeridas
*/
void menuSencillo(int comando) {
	system("CLS");
	try{
	using namespace std;
		if(comando == 1){ // Registrar Usuario
			string ci, nombre;
			cout << "Ingrese Nombre: " << endl;
			cin >> nombre;
			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			
			registrarUsuario(ci, nombre);

			cout << "Usuario fue agregado correctamente!" << endl;
		
		}else if(comando == 2){ //Agregar Vehiculo
			cout << "Desea ingresar un monopatin (m) o bicicleta (b) (ingresar letra en minuscula)?" << endl;
			char tipo;
			cin >> tipo;
			int cantidad, nroSerie;
			float porcentaje, precio;
			cout << "Ingrese nro de serie: " << endl;
			cin >> nroSerie;
			cout << "Ingrese porcentaje de bateria: " << endl;
			cin >> porcentaje;
			cout << "Ingrese precio base: " << endl;
			cin >> precio;
			DtVehiculo *vehiculo;
			if (tipo == 'm') {
				cout << "Tiene luces? [y/n]?";
				cin >> tipo;
				bool luces = (tipo == 'y');

				vehiculo = new DtMonopatin(nroSerie, porcentaje, precio, luces);
				agregarVehiculo(*vehiculo);
			}
			else if (tipo == 'b') {
				cout << "¿Es de tipo montania? [y/n]" << endl;
				cin >> tipo;
				cout << "¿Cantidad de cambios?" << endl;
				cin >> cantidad;
				if (tipo == 'y') {
					cout << "Bicicleta de tipo Montania" << endl;
					DtBicicleta* bici;
					bici = new DtBicicleta(nroSerie, porcentaje, precio, MONTANIA, cantidad);
					vehiculo = bici;
				}
				else {
					cout << "Bicicleta de tipo Paseo" << endl;
					vehiculo = new DtBicicleta(nroSerie, porcentaje, precio, PASEO, cantidad);
				}
				agregarVehiculo(*vehiculo);
			}
			else {
				cout << "Ingrese un tipo correcto";
			}

			cout << "El vehiculo fue agregado correctamente!" << endl;
		}else if(comando == 3){ //Ingresar Viaje
			string ci;
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
			cin >> distancia_arg;
			DtFecha fecha_arg = DtFecha(di, me, an);
			DtViajeBase viaje = DtViajeBase(fecha_arg, duracion_arg, distancia_arg);
			ingresarViaje(ci, nroSerieVehiculo,  	viaje);
			cout << "El viaje fue ingresado correctamente!" << endl;

		}else if (comando == 4) { // Ver Viaje Antes de Fecha
			int dia, mes, anio, cantViajes = 0;
			string ci;
			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese dia: " << endl;
			cin >> dia;
			cout << "Ingrese mes: " << endl;
			cin >> mes;
			cout << "Ingrese anio: " << endl;
			cin >> anio;
			DtFecha fecha_arg = DtFecha(dia, mes, anio);
			DtViaje** viajes_antes = verViajesAntesDeFecha(fecha_arg, ci, cantViajes);
			cout << "El usuario de CI " << ci << " hizo " << cantViajes << " viajes." << endl;
            int i = 0;             
            while(i < cantViajes){                              //A partir de aca agregue
                fecha_arg = viajes_antes[i]->getFecha();
                cout << "Viaje Nro: " << i << endl;
                cout << "Dia: " << fecha_arg.getDia() << endl;
                cout << "Mes: " << fecha_arg.getMes() << endl;
                cout << "Anio: " << fecha_arg.getAnio() << endl;
                cout << "Duracion: " << viajes_antes[i]->getDuracion() << endl;
                cout << "Distancia_recorrida: " << viajes_antes[i]->getDistancia() << endl;
                cout << "Precio total: " << viajes_antes[i]->getprecioTotal() << endl;
				cout << "Vehiculo" << endl;
                DtVehiculo *vehiculo_usado = viajes_antes[i]->getvehiculo();              
               	
                
                DtMonopatin *monopatin_usado = dynamic_cast<DtMonopatin*>(vehiculo_usado);
                DtBicicleta *bicicleta_usado = dynamic_cast<DtBicicleta*>(vehiculo_usado);
                
                if(monopatin_usado != NULL){
                    cout << monopatin_usado->gettieneLuces();
                }else{
                    cout << bicicleta_usado->getcantCambios();                //cout ¿?
                }
				i++;
            };
			for (int i = 0; i < cantViajes; i++) {
				delete viajes_antes[i];
				
			}
			delete[] viajes_antes;
		}else if(comando ==5){ // Eliminar Viajes
			string ci;
			
			int dia, mes, anio;

			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese dia: " << endl;
			cin >> dia;
			cout << "Ingrese mes: " << endl;
			cin >> mes;
			cout << "Ingrese anio: " << endl;
			cin >> anio;
			
			DtFecha fecha(dia, mes, anio);

			eliminarViajes(ci, fecha);


			cout << "El viaje fue eliminado correctamente!" << endl;

		}else if (comando == 6) { // Cambiar Bateria de Vehiculo
			int nroSerieVehiculo;
			float cargaVehiculo;
			cout << "Ingrese nro de serie de vehiculo";
			cin >> nroSerieVehiculo;
			cout << "Ingrese nueva carga del vehiculo";
			cin >> cargaVehiculo;
			cout << "Bateria actualizada!" <<endl;

		}else if(comando == 7){ // Obtener Vehiculo

			int cantidad = 0;
			DtVehiculo** arreglo = obtenerVehiculos(cantidad);
			cout << "Hay " << cantidad << " vehiculos ingresados en el sistema" << endl;
			int i = 0;
			while (i < cantidad) {
				cout << arreglo[i];
				i++;
			}
			while (i < cantidad) {
				delete arreglo[i];
				i++;
			}delete arreglo;
		}
		else {
		cout << "Comando no reconocido, intente nuevamente" << endl;
		cout << endl;
		}
	}catch (const std::exception &invalid_argument) {
       //  cerr << invalid_argument.what() << endl;
		std::cout << "error" << std::endl;
    }
}

int main(){
	using namespace std;
	for (int i = 0; i < MAX_USUARIOS; i++)
		Usuarios[i] = NULL;
	for (int i = 0; i < MAX_VEHICULOS; i++)
		Vehiculos[i] = NULL;

	int comando = -1;
	while (comando != 0) {
	
		cout << "Bienvenido. Elija una opcion:" << endl;
		cout << "1) Registrar usuario" << endl;
		cout << "2) Agregar vehiculo" << endl;
		cout << "3) Ingresar viaje" << endl;
		cout << "4) Ver viajes antes de la una fecha" << endl;
		cout << "5) Eliminar viajes" << endl;
		cout << "6) Cambiar bateria de un vehiculo" << endl;
		cout << "7) Obtener vehiculos" << endl;
		cout << "0) Salir" << endl;

		cout << "Opcion: ";
		cin >> comando;
		if (comando != 0) {
			menuSencillo(comando);
		}
	}

	system("CLS");

	return 0;
}
