#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>
#include <string>

#include "../Header/DtComida.h"


using namespace std;

class Comida{
private:
    string descripcion;
    string codigo;
public:
	//Const
	Comida(string codigo, string descripcion);
	//seters

	void setDescripcion(string desc);
	void setCodigo(string codigo);

	//geters

	int getPrecio();
	string getDescripcion();
	string getCodigo();


	//Virutal
    virtual bool esProducto() = 0;
    virtual DtComida *darDataType() = 0;
 
	//Otras  
	bool sonIguales(string codigo);
    void darDeBajaComida();
	


	virtual ~Comida() = 0;

};
#endif