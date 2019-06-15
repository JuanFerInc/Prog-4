#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
 
using namespace std;


class DtDireccion {
private:
	string nombreCalle, numero, calleAdyacente;

public:
	DtDireccion() = default;
	DtDireccion(const DtDireccion &direccion);

	DtDireccion(string numero,  string calle, string calleAdyacente) ;

//geters
	string getNombreCalle()const;
	string getNumero()const;
	string getCalleAdyacente()const;


	friend std::ostream& operator<<(std::ostream& out, DtDireccion *info);
	virtual void print(ostream& out);
    virtual ~DtDireccion() {};

};


#endif
