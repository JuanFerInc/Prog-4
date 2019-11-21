#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "DtFecha.h"

#include "viaje.h"


class Usuario{
private:
	std::string cedula, nombre;
	DtFecha fechaingreso;
	Viaje *Viajes[100];

public:
	//constructor
	Usuario();
	//Ususario(ci,nombre,fecha)
	Usuario(std::string, std::string, DtFecha);

	//getters
	std::string getCedula();
	std::string getNombre();
	DtFecha getFechaIngreso();

	//setters
	void setCedula(std::string);
	void setNombre(std::string);
	void setFechaIngreso(DtFecha);


	//Destructors
	~Usuario();

	//Otras
	bool agregarViaje(Viaje*); //Si el usuario tiene 100 viajes no hace nada	
	void eliminarViaje(Viaje); //Si el usuario no tiene viajes o no esta Viaje no hace nada
	void eliminarViaje(DtFecha); //Elimina todos los viajes hechos en esa fecha si no hay ninguno no hace nada
	int contarViajes(const DtFecha&);
	Viaje** arregloViajesMenores(const DtFecha&, int);



	//nueva funicones
	//cuenta la cantidad de viajes que estan entre fecha inicio y fecha fin
	int contarViajesEntre(const DtFecha& , const DtFecha& );

	//retorna un arrelgo con los vaijes que estan entre fecha inicio y fecha fin
	Viaje** arregloViajesEntre(const DtFecha& , const DtFecha& , int );
};

#endif