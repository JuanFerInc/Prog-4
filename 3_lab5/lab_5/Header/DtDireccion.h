#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
 
using namespace std;


class DtDireccion {
private:
	string nombreCalle, numero, calleAdyacente;

public:
	string getNombreCalle();
	string getNumero();
	string getCalleAdyacente();
};

class DtApartamento : public DtDireccion {
private:
	string nombreEdificio, numeroApartamento;

public: 
	string getNombreEdificio();
	string getNumeroApartamento();

};
#endif