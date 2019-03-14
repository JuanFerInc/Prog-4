#include "..DtFecha.h"
#include <string>

class Viaje{
private:
		DtFecha fecha;
		int distancia, duracion;
		Usuario *viajero;
		Vehiculo *viajaen;
public:
		//Constructors
		Viaje();
		Viaje(DtFecha, int, int);


		//getters
		DtFecha getfecha();
		int getdistancia();
		int getduracion();

		//setters
		void setfecha(DtFecha);
		void setdistancia(int);
		void setduracion(int);
		void setEsViajeDe(Usuario);
		void setViajaEn(Vehiculo);

		//Destructor
		~Viaje();

		//Otras
		bool operator!=(Viaje);
}