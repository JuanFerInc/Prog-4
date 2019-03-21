#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "DtFecha.h"
#include "DtViaje.h"
//#include "viaje.h"

class Viaje;


class Usuario{
private:
	std::string cedula, nombre;
	DtFecha fechaingreso;
	Viaje *Viajes[100];

public:
	//constructor
	Usuario();
	Usuario(std::string, std::string, DtFecha);

	//getters
	std::string getCedula();
	std::string getNombre();
	DtFecha getFechaIngreso();
	//Viaje** getViajes()       //Revisar si es asi el arreglo dinámico 


	//setters
	void setCedula(std::string);
	void setNombre(std::string);
	void setFechaIngreso(DtFecha);
	//void setViajes(Viaje*);      //Capaz no es necesario



	//Destructors
	~Usuario();

	//Otras
	bool agregarViaje(Viaje); //Si el usuario tiene 100 viajes no hace nada
	void eliminarViaje(Viaje); //Si el usuario no tiene viajes o no esta Viaje no hace nada
	void eliminarViaje(DtFecha); //Elimina todos los viajes hechos en esa fecha si no hay ninguno no hace nada
	int contarViajes(const DtFecha&);
	DtViaje** arregloViajesMenores(const DtFecha&, int);
};

#include "viaje.h"

#endif