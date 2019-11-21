#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <set>
#include <thread>
#include <vector>
#include <mutex>

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


#define MAX_VEHICULOS 3
#define MAX_USUARIOS 5


Usuario *Usuarios[MAX_USUARIOS];
Vehiculo *Vehiculos[MAX_VEHICULOS];

using namespace std;

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
static bool distanciaValida(DtViajeBase via) {//ins
	return (via.getDistancia() > 0);
}

static bool noestallenoUsuarios() {//ins
	bool res = false;
	int i = 0;
	while ((i < MAX_USUARIOS) && (!res)) {
		if (Usuarios[i] == NULL) {
			res = true;
		}
		i++;
	}
	return res;
}

static bool noestallenoVehiculos() {
	bool res = false;
	int i = 0;
	while ((i < MAX_VEHICULOS) && (!res)) {
		if (Vehiculos[i] == NULL) {
			res = true;
		}
		i++;
	}
	return res;
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
	using namespace std;
	DtViajeBase via = DtViajeBase(viaje);
	Usuario* usu = existeUsuario(ci);
	Vehiculo* vehiculo = existeVehiculo(nroSerieVehiculo);
	if (usu == NULL) {
		cout << "No existe usuario" << endl;
		throw std::invalid_argument("No existe usuario");
	}
	else {
		if (vehiculo == NULL) {
			cout << "No existe vehiculo" << endl;
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
						cout << "Fecha invalida" << endl;
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
		Viajes = p->arregloViajesMenores(fechita, cantViajes);//no se borra
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
				//throw std::exception("No se pudo convertir de Vehiculo a una de sus clases derivadas");
				throw std::exception();
			}

			DtViaje *data_viaje = new DtViaje(Viajes[i]->getfecha(), Viajes[i]->getduracion(), Viajes[i]->getdistancia(), Viajes[i]->getPrecioViaje(), data_vehiculo);
			
			res[i] = data_viaje;

		}
	}

	delete[] Viajes;
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
Calcula el total recaudado entre las fechas de los usuarios seleccionados
*/
float calcularTotalEntreFechas(const DtFecha& desde, const DtFecha& hasta, set<string> cedula) {
	set<string>::iterator iter;
	vector<thread> threads;
	float total = 0;
	mutex totalLock;


	/*
	lambda?
	Pide los viajes que cumplen la condicion, por cada viaje pide el total del viaje y se lo suma al total global
	totalLock es un mutex limitando el acceso a la variable total
	*/
	auto calcualrTotalEntreFechasUsuario = [&desde, &hasta, &total, &totalLock](string ci) {
		Usuario* u = existeUsuario(ci);
		Viaje** Viajes = NULL;
		float precioViaje = 0;
		if (u != NULL) {

			int cantViajes = u->contarViajesEntre(desde, hasta);
			Viajes = u->arregloViajesEntre(desde, hasta, cantViajes);
			int subTotal = 0;

			for (int i = 0; i < cantViajes; i++) {
				precioViaje = Viajes[i]->getPrecioViaje();
				subTotal = subTotal + precioViaje;
				
			}
			/*
			Excluye el acceso a la variable total en el momento de actualizar
			*/
			totalLock.lock();
			total = total + subTotal;
			totalLock.unlock();
		}

	};


	/*
	Crea un thread por cada c.i.  guardando la referencia a los threads en un set para poder  
	mantener un control de la cantidad de  hilos a unificar al final antes de retornal el total
	*/
	for (iter = cedula.begin(); iter != cedula.end(); iter++) {
		//meto los thread en un vector ya que no se cuantos son y necesito esperar que terminen todos
		threads.emplace_back(thread(calcualrTotalEntreFechasUsuario, *iter));

	}

	/*
	Recorre el vector uniendo los hilos, 
	no importa el orden en que terminan solo que todos terminen.
	*/
	for (auto& th : threads) {
		th.join();
	}


	return total;

}

void cargarDatos() {
	//cargar usuarios
	registrarUsuario("1", "Usuario1");
	registrarUsuario("2", "Usuario2");
	registrarUsuario("3", "Usuario3");
	registrarUsuario("4", "Usuario4");
	registrarUsuario("5", "Usuario5");

	//cargar vehiculos
	agregarVehiculo(DtBicicleta(1, 20, 30, MONTANIA, 10));
	agregarVehiculo(DtMonopatin(2, 10, 20, true));
	agregarVehiculo(DtMonopatin(3, 10, 20, false));
	//cargar viajes
	//Usuario 1
	ingresarViaje("1", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 56));
	ingresarViaje("1", 2, DtViajeBase(DtFecha(22, 11, 2020), 10, 15));
	
	//Usuario2
	ingresarViaje("2", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 75));
	ingresarViaje("2", 1, DtViajeBase(DtFecha(22, 11, 2020), 8, 15));
	ingresarViaje("2", 2, DtViajeBase(DtFecha(23, 12, 2020), 10, 75));
	ingresarViaje("2", 3, DtViajeBase(DtFecha(29, 12, 2020), 4, 15));

	//Usuario3
	ingresarViaje("3", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 15));
	ingresarViaje("3", 2, DtViajeBase(DtFecha(22, 11, 2020), 9, 256));
	ingresarViaje("3", 3, DtViajeBase(DtFecha(27, 12, 2020), 10, 15));

	//Usuario4
	ingresarViaje("4", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 201));
	ingresarViaje("4", 2, DtViajeBase(DtFecha(22, 1, 2021), 3, 15));
	ingresarViaje("4", 2, DtViajeBase(DtFecha(23, 11, 2020), 10, 31));
	ingresarViaje("4", 1, DtViajeBase(DtFecha(24, 11, 2020), 10, 15));
	ingresarViaje("4", 2, DtViajeBase(DtFecha(25, 10, 2021), 2, 12));
	ingresarViaje("4", 3, DtViajeBase(DtFecha(26, 1, 2021), 10, 15));

	//Usuario5
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 15));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(25, 11, 2020), 5, 100));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(20, 11, 2020), 10, 15));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 11, 2020), 9, 99));
	ingresarViaje("5", 2, DtViajeBase(DtFecha(21, 11, 2020), 10, 15));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(21, 11, 2020), 7, 88));
	ingresarViaje("5", 2, DtViajeBase(DtFecha(21, 11, 2020), 10, 15));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(21, 12, 2020), 45, 15));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(21, 12, 2020), 10, 9));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(2, 1, 2021), 22, 15));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 1, 2021), 123, 15));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(23, 1, 2021), 10, 58));
	ingresarViaje("5", 2, DtViajeBase(DtFecha(21, 2, 2021), 13, 12));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 11, 2020), 10, 2));
	ingresarViaje("5", 3, DtViajeBase(DtFecha(21, 11, 2021), 5, 12));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 11, 2021), 455, 23));
	ingresarViaje("5", 1, DtViajeBase(DtFecha(21, 11, 2022), 5, 20));
}

/*
Menu sencillo interactivo para poder probar 
las funcionalidades requeridas
*/
int menuSencillo(int comando) {
	system("CLS");
	try{
	using namespace std;
		if(comando == 1){ // Registrar Usuario
			if (noestallenoUsuarios()) {
				string ci, nombre;
				cout << "Ingrese Nombre: " << endl;
				cin >> nombre;
				cout << "Ingrese Cedula: " << endl;
				cin >> ci;
				try{
					registrarUsuario(ci, nombre);
					cout << "Usuario fue agregado correctamente!" << endl;
				}catch(const std::exception &invalid_argument){
					cout << "El usuario de CI " << ci <<  "ya esta ingresado en el sistema" << endl;
					return 0;
				}
			}
			else {
				cout << "Se ha alcanzado la capacidad maxima, usuario no agregado" << endl;
			}
		}else if(comando == 2){ //Agregar Vehiculo
			if (noestallenoVehiculos()) {
				cout << "Desea ingresar un monopatin (m) o bicicleta (b) (ingresar letra en minuscula)?" << endl;
				char tipo;
				cin >> tipo;
				if((tipo != 'b') && (tipo != 'm')){
					cout << "Debe decidirse por bicicleta o monopatin" << endl;
					return 0;
				}
				int cantidad, nroSerie;
				float porcentaje, precio;
				cout << "Ingrese Nro de serie: " << endl;
				cin >> nroSerie;
				if(!cin){
					cout << "El numero de serie debe ser un 'entero'" << endl;
					return 0;
				}
				cout << "Ingrese porcentaje de bateria: " << endl;
				cin >> porcentaje;
				if((!cin) || (porcentaje < 0) || (porcentaje > 100)) {
					cout << "La bateria debe ser un real entre 0 y 100" << endl;
					return 0;
				}
				cout << "Ingrese precio base: " << endl;
				cin >> precio;
				if(!cin){
					cout << "El precio debe ser un real" << endl;
				}
				DtVehiculo *vehiculo;

				if (tipo == 'm') {
					cout << "Tiene luces? [y/n]?";
					cin >> tipo;
					if((!cin) ||((tipo != 'y') && (tipo != 'n'))){
						cout << "Las respuestas posibles son y (si) o n (no)" << endl;
						return 0;
					}
					bool luces = (tipo == 'y');

					vehiculo = new DtMonopatin(nroSerie, porcentaje, precio, luces);
					try{
						agregarVehiculo(*vehiculo);
						delete vehiculo;
						cout << "El vehiculo fue agregado correctamente!" << endl;
					}catch(const std::exception &invalid_argument){
							delete vehiculo;
							cout << "Vehiculo ya existe"<< endl;
						}
		

				}else if (tipo == 'b') {
					cout << "Es de tipo montania? [y/n]" << endl;
					cin >> tipo;
					if((!cin) ||((tipo != 'y') && (tipo != 'n'))){
						cout << "Las respuestas posibles son y (si) o n (no)" << endl;
						return 0;
					}
					cout << "Cantidad de cambios?" << endl;
					cin >> cantidad;
					if((!cin) || cantidad <= 0){
						cout << "La cantidad de cambios debe ser un entero positivo" << endl;
						return 0;
					}
					if (tipo == 'y') {
						cout << "Bicicleta de tipo Montania" << endl;
						
						vehiculo = new DtBicicleta(nroSerie, porcentaje, precio, MONTANIA, cantidad);
						try{
							agregarVehiculo(*vehiculo);	
							delete vehiculo;
							cout << "El vehiculo fue agregado correctamente!" << endl;
						}catch(const std::exception &invalid_argument){
							delete vehiculo;
							cout << "Vehiculo ya existe"<< endl;
						}
						
						
					}else {

						cout << "Bicicleta de tipo Paseo" << endl;
						vehiculo = new DtBicicleta(nroSerie, porcentaje, precio, PASEO, cantidad);
						try{

							agregarVehiculo(*vehiculo);
							delete vehiculo;
							cout << "El vehiculo fue agregado correctamente!" << endl;	
						}catch(const std::exception &invalid_argument){
							delete vehiculo;
							cout << "Vehiculo ya existe"<< endl;
						}
						
					}
				
				}else {
					cout << "Ingrese un tipo correcto" << endl;
				}

				
			}
			else {
				cout << "Se ha alcanzado la capacidad maxima, vehiculo no agregado" << endl;
			}
		}else if(comando == 3){ //Ingresar Viaje
			string ci;
			int nroSerieVehiculo, di, me, an, duracion_arg, distancia_arg;
			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese nro de serie del vehiculo: " << endl;
			cin >> nroSerieVehiculo;
			if(!cin){
				cout << "El numero de serie debe ser un 'entero'" << endl;
				return 0;
			}
			cout << "Ingrese dia: " << endl;
			cin >> di;
			if((!cin) || (di > 31) || (di < 0)){
				cout << "Ingrese un dia valido" << endl;
				return 0;
			}
			cout << "Ingrese mes: " << endl;
			cin >> me;
			bool mesdetreinta = ((me == 4) || (me == 6) || (me == 9) || (me == 11));
			if((!cin) || (me > 12) || (me < 0) || ((me == 2) && (di > 29)) || ((mesdetreinta) && ( di == 31))){				//Controlar la cantidad de dias del mes (ademas de las otras giladas)
				cout << "Ingrese un mes valido con respecto al dia colocado anteriormente" << endl;
				return 0;
			}
			cout << "Ingrese anio: " << endl;
			cin >> an;
			if((!cin) || ((an % 4 != 0 ) && (di == 29))){			//Este chequeo es de bisiesto (hay que verlo bien)
				cout << "Ingrese un anio valido con respecto al dia y mes colocado anteriormente" << endl;
				return 0;
			}
			cout << "Ingrese duracion: " << endl;
			cin >> duracion_arg;
			if((!cin) || (duracion_arg < 0)){
				cout << "Ingrese una duracion valida" << endl;
				return 0;
			}
			cout << "Ingrese distancia recorrida: " << endl;
			cin >> distancia_arg;
			if((!cin) || (distancia_arg < 0)){
				cout << "Ingrese una distancia valida" << endl;
				return 0;
			}
			DtFecha fecha_arg = DtFecha(di, me, an);
			DtViajeBase viaje = DtViajeBase(fecha_arg, duracion_arg, distancia_arg);
			ingresarViaje(ci, nroSerieVehiculo,  	viaje);
			cout << endl;
			cout << "El viaje fue ingresado correctamente!" << endl;

		}else if (comando == 4) { // Ver Viaje Antes de Fecha //falta mirar 4
			int di, me, an, cantViajes = 0;
			string ci;
			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
						cout << "Ingrese dia: " << endl;
			cin >> di;
			if((!cin) || (di > 31) || (di < 0)){
				cout << "Ingrese un dia valido" << endl;
				return 0;
			}
			cout << "Ingrese mes: " << endl;
			cin >> me;
			bool mesdetreinta = ((me == 4) || (me == 6) || (me == 9) || (me == 11));
			if((!cin) || (me > 12) || (me < 0) || ((me == 2) && (di > 29)) || ((mesdetreinta) && ( di == 31))){				//Controlar la cantidad de dias del mes (ademas de las otras giladas)
				cout << "Ingrese un mes valido con respecto al dia colocado anteriormente" << endl;
				return 0;
			}
			cout << "Ingrese anio: " << endl;
			cin >> an;
			if((!cin) || ((an % 4 != 0 ) && (di == 29))) {			//Este chequeo es de bisiesto (hay que verlo bien)
				cout << "Ingrese un anio valido con respecto al dia y mes colocado anteriormente" << endl;
				return 0;
			}
			DtFecha fecha_arg = DtFecha(di, me, an);
			DtViaje** viajes_antes = verViajesAntesDeFecha(fecha_arg, ci, cantViajes);
			cout << "El usuario de CI " << ci << " hizo " << cantViajes << " viajes." << endl;
            int i = 0;             
            while(i < cantViajes){                              //A partir de aca agregue
                fecha_arg = viajes_antes[i]->getFecha();
                cout << "Viaje Nro: " << i+1 << endl;
                cout << "Dia: " << fecha_arg.getDia() << endl;
                cout << "Mes: " << fecha_arg.getMes() << endl;
                cout << "Anio: " << fecha_arg.getAnio() << endl;
                cout << "Duracion: " << viajes_antes[i]->getDuracion() << endl;
                cout << "Distancia_recorrida: " << viajes_antes[i]->getDistancia() << endl;
                cout << "Precio total: " << viajes_antes[i]->getprecioTotal() << endl;
				cout << endl;
				cout << "Vehiculo: " << endl << viajes_antes[i]->getvehiculo() << endl;
               // DtVehiculo *vehiculo_usado = viajes_antes[i]->getvehiculo();              
               	
                
               // DtMonopatin *monopatin_usado = dynamic_cast<DtMonopatin*>(vehiculo_usado);
               // DtBicicleta *bicicleta_usado = dynamic_cast<DtBicicleta*>(vehiculo_usado);
                
               // if(monopatin_usado != NULL){
                //    cout << monopatin_usado->gettieneLuces();
                //}else{
                //    cout << bicicleta_usado->getcantCambios();                //cout ¿?
               // }
				i++;
            };
			for (int i = 0; i < cantViajes; i++) {
				delete viajes_antes[i];
				
			}
			delete[] viajes_antes;

		}else if(comando ==5){ // Eliminar Viajes
			string ci;

			int di, me, an;

			cout << "Ingrese Cedula: " << endl;
			cin >> ci;
			cout << "Ingrese dia: " << endl;
			cin >> di;
			if ((!cin) || (di > 31) || (di < 0)) {
				cout << "Ingrese un dia valido" << endl;
				return 0;
			}
			cout << "Ingrese mes: " << endl;
			cin >> me;
			bool mesdetreinta = ((me == 4) || (me == 6) || (me == 9) || (me == 11));
			if ((!cin) || (me > 12) || (me < 0) || ((me == 2) && (di > 29)) || ((mesdetreinta) && (di == 31))) {				//Controlar la cantidad de dias del mes (ademas de las otras giladas)
				cout << "Ingrese un mes valido con respecto al dia colocado anteriormente" << endl;
				return 0;
			}
			cout << "Ingrese anio: " << endl;
			cin >> an;
			if ((!cin) || ((an % 4 != 0) && (di == 29))) {			//Este chequeo es de bisiesto (hay que verlo bien)
				cout << "Ingrese un anio valido con respecto al dia y mes colocado anteriormente" << endl;
				return 0;
			}

			DtFecha fecha(di, me, an);
			try {
				eliminarViajes(ci, fecha);
				cout << "El viaje fue eliminado correctamente!" << endl;
			}
			catch (const std::exception & invalid_argument) {
				cout << "El usuario no existe" << endl;
				return 0;
			}





		}else if (comando == 6) { // Cambiar Bateria de Vehiculo
			int nroSerieVehiculo;
			float cargaVehiculo;
			cout << "Ingrese nro de serie de vehiculo: ";
			cin >> nroSerieVehiculo;
			cout << "Ingrese nueva carga del vehiculo: ";
			cin >> cargaVehiculo;
			if(!cin){
				cout << "La bateria debe ser real entre 0 y 100" << endl;
				return 0;
			}
			try{
				cambiarBateriaVehiculo(nroSerieVehiculo,cargaVehiculo);
				cout << "Bateria actualizada!" <<endl;
			}catch(const std::exception &invalid_argument){
				cout << "La bateria debe ser real entre 0 y 100" << endl;
				return 0;
			}
	



		}else if(comando == 7){ // Obtener Vehiculo

			int cantidad = 0;
			DtVehiculo** arreglo = obtenerVehiculos(cantidad);
			cout << "Hay " << cantidad << " vehiculos ingresados en el sistema" << endl;
			int i = 0;
			while (i < cantidad) {
				cout<<endl;
				cout << "Vehiculo " << i+1 <<endl;
				cout << endl;
				cout << arreglo[i];
				i++;
			}
			i = 0;
			while (i < cantidad) {
				delete arreglo[i];
				i++;
			}
			delete[] arreglo;
		}
		else if (comando == 8) {
		set<string> cedulas;
		int di, me, an;
		cout << "Porfavor ingrese la fecha inicio" << endl;
		cout << "Ingrese dia: " << endl;
		cin >> di;
		if ((!cin) || (di > 31) || (di < 0)) {
			cout << "Ingrese un dia valido" << endl;
			return 0;
		}
		cout << "Ingrese mes: " << endl;
		cin >> me;
		bool mesdetreinta = ((me == 4) || (me == 6) || (me == 9) || (me == 11));
		if ((!cin) || (me > 12) || (me < 0) || ((me == 2) && (di > 29)) || ((mesdetreinta) && (di == 31))) {				//Controlar la cantidad de dias del mes (ademas de las otras giladas)
			cout << "Ingrese un mes valido con respecto al dia colocado anteriormente" << endl;
			return 0;
		}
		cout << "Ingrese anio: " << endl;
		cin >> an;
		if ((!cin) || ((an % 4 != 0) && (di == 29))) {			//Este chequeo es de bisiesto (hay que verlo bien)
			cout << "Ingrese un anio valido con respecto al dia y mes colocado anteriormente" << endl;
			return 0;
		}

		DtFecha inicio(di, me, an);
		cout << "Porfavor ingrese la fecha fin" << endl;
		cout << "Ingrese dia: " << endl;
		cin >> di;
		if ((!cin) || (di > 31) || (di < 0)) {
			cout << "Ingrese un dia valido" << endl;
			return 0;
		}
		cout << "Ingrese mes: " << endl;
		cin >> me;
		mesdetreinta = ((me == 4) || (me == 6) || (me == 9) || (me == 11));
		if ((!cin) || (me > 12) || (me < 0) || ((me == 2) && (di > 29)) || ((mesdetreinta) && (di == 31))) {				//Controlar la cantidad de dias del mes (ademas de las otras giladas)
			cout << "Ingrese un mes valido con respecto al dia colocado anteriormente" << endl;
			return 0;
		}
		cout << "Ingrese anio: " << endl;
		cin >> an;
		if ((!cin) || ((an % 4 != 0) && (di == 29))) {			//Este chequeo es de bisiesto (hay que verlo bien)
			cout << "Ingrese un anio valido con respecto al dia y mes colocado anteriormente" << endl;
			return 0;
		}

		DtFecha fin(di, me, an);
		int salida = 1;
		string ci;
		while (salida != 0) {
			cout << "Ingrese la cedula o 0 para salir: ";
			cin >> ci;
			if (ci.compare("0") != 0) {


				cedulas.insert(ci);
				cout << endl;
			}
			else {
				salida = 0;
			}
		}
		
		
		cout << "El total es: " << calcularTotalEntreFechas(inicio, fin, cedulas);
		}
		else {
			
		
		cout << "Comando no reconocido, intente nuevamente" << endl;
		cout << endl;
		}
	}catch (const std::exception &invalid_argument) {
       //  cerr << invalid_argument.what() << endl;
		std::cout << "Error no especificado" << std::endl;
		return 0;
    }
	return 1;
}


int main(){
	using namespace std;
	for (int i = 0; i < MAX_USUARIOS; i++)
		Usuarios[i] = NULL;
	for (int i = 0; i < MAX_VEHICULOS; i++)
		Vehiculos[i] = NULL;


	cargarDatos();

	int comando = -1;
	while (comando != 0) {
		using std::cout;
		using std::cin;
		cout << endl;
		cout << "Bienvenido. Elija una opcion:" << endl;
		cout << "1) Registrar usuario" << endl;
		cout << "2) Agregar vehiculo" << endl;
		cout << "3) Ingresar viaje" << endl;
		cout << "4) Ver viajes antes de una fecha" << endl;
		cout << "5) Eliminar viajes" << endl;
		cout << "6) Cambiar bateria de un vehiculo" << endl;
		cout << "7) Obtener vehiculos" << endl;
		cout << "8) Calcular total entre fechas" << endl;
		cout << "0) Salir" << endl;

		cout << "Opcion: ";
		cin >> comando;
		if (comando != 0) {
			if (menuSencillo(comando) == 0) {
				cout << "Debido al error anterior debemos solicitarle que vuelva a intentarlo" << endl;
			}
		}
	}
	for (int i = 0; i < MAX_USUARIOS; i++) {
		delete Usuarios[i];

	}

	for (int i = 0; i < MAX_VEHICULOS; i++) {
		delete Vehiculos[i];
	}

	system("CLS");

	return 0;
}
