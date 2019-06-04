#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
 
using namespace std;


class DtDireccion {
private:
	string nombreCalle, numero, calleAdyacente;

public:
//geters
	string getNombreCalle();
	string getNumero();
	string getCalleAdyacente();
};


#endif