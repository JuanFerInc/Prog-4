#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
 
using namespace std;


class DtDireccion {
private:
	string nombreCalle, numero, calleAdyacente;

public:
	DtDireccion(string numero, string calle, string esquinas);
//geters
	string getNombreCalle();
	string getNumero();
	string getCalleAdyacente();
	friend std::ostream& operator<<(std::ostream& out, DtDireccion*info);
	virtual void print(std::ostream& out);
};


#endif