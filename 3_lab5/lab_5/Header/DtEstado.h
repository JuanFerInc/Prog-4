#ifndef DTESTADO_H
#define DTESTADO_H

#include <iostream>
#include <set>
#include <string>

using namespace std;


class DtEstado {
private:
	string etapaActual;

public:
	//Contructor por copia
	DtEstado(const DtEstado &e);

	DtEstado(string c);
	string getEtapaActual() const;

	friend std::ostream& operator<<(std::ostream& out, DtEstado *info);
	virtual void print(ostream& out);
};

#endif