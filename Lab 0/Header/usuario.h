#include "../fecha.h"
#include <string>


class Usuario{
private: 
		string cedula, nombre;
		DtFecha fechaingreso;
		Viaje *Viajes[100];

public: 
		//constructor
		Usuario();
		Usuario(string, string, DtFecha);

		//getters
		string getCedula();
		string getNombre();
		DtFecha getFechaIngreso();



		//setters
		void setCedula(string);
		void setNombre(string);
		void setFechaIngreso(DtFecha);




		//Destructors
		~Usuario();

		//Otras
		void AgregarViaje(Viaje); //Si el usuario tiene 100 viajes no hace nada
		void EliminarViaje(Viaje); //Si el usuario no tiene viajes o no esta Viaje no hace nada

}