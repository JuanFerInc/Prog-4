#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo {
private:
	int nroSerie;
	float porcentajeBateria;
	float precioBase;
public:
	//Cons
	Vehiculo();
	//Vehiculo(nroSerie,porcentajeBateria,percioBase)
	Vehiculo(int, float, float);
	//Get
	int getnroSerie();
	float getporcentajeBateria();
	float getprecioBase();
	//Set
	void setnroSerie(int);
	void setporcentajeBateria(float);
	void setprecioBase(float);
	//Def
	float virtual darPrecioViaje(int, int) = 0;

};

#endif