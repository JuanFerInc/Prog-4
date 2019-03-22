#ifndef DTVEHICULO_H
#define DTVEHICULO_H
#include <iostream>

class DtVehiculo {
	private:
		int nroSerie;
		float porcentaje;
		float precioBase;
	public:
		//Constructor
		DtVehiculo();
		//DtVehiculo(nroSerie ,porcentaje ,precioBase)
		DtVehiculo( int ,  float ,  float);

		//Getters
		int getnroSerie() const;
		float getporcentajeBateria() const;
		float getprecioBase() const;
		friend std::ostream& operator<<(std::ostream&, DtVehiculo*);
		virtual void print(std::ostream&)=0;

		virtual ~DtVehiculo() = default;
};		
#endif 