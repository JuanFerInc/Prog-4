#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>
#include <string>

#include "../Header/DtComida.h"



class Comida{

protected:
    string descripcion;
    string codigo;
	int cantitatUnidadesFacturadas;

public:
	//Const
	Comida(string codigo, string descripcion);
	
	//seters
	void setDescripcion(string desc);
	
	void setCodigo(string codigo);

	//geters
	virtual int getPrecio() = 0;

	string getDescripcion();

	string getCodigo();


	//Virutal
    virtual DtComida *darDataType() = 0;
 
	//Otras  
	bool sonIguales(string codigo);

    virtual void darDeBajaComida() = 0;
	virtual DtComida* darDataVenta() = 0;
	//Franco no uses esta funcion
	void incrementarCantidadUnidadesVendidas(int jorge);
	virtual ~Comida() {};

};
#endif