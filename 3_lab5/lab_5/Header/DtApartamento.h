#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H	

#include "../Header/DtDireccion.h"


class DtApartamento : public DtDireccion {
private:
	string nombreEdificio, numeroApartamento;

public:
	DtApartamento(string nombreEdificio, string numeroApart, string calle, string adyacente, string numeroPuerta);
	//Contructor por copia
	DtApartamento(const DtApartamento &apart);
	//geters
	string getNombreEdificio();
	string getNumeroApartamento();

	void print(std::ostream& out);
};
#endif