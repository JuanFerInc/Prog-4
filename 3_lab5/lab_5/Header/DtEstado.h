#ifndef DTESTADO_H
#define DTESTADO_H

#include <iostream>
#include <set>


using namespace std;


class DtEstado {
private:
	string etapaActual;

public:
	//Contructor por copia
	DtEstado(const DtEstado &e);

	DtEstado(string c);
	string getEtapaActual() const;
};

#endif