#ifndef DTCOMIDA_H
#define DTCOMIDA_H

#include <map>
#include <set>

using namespace std;

class DtComida {
private:
	string codigo, descripcion;
	int precioTotal;

public:
	DtComida(string codigo, string descripcion, int precioTotal);
	string getCodigo();
	string getDescripcion();
	int getPrecioTotal();
	virtual void print(std::ostream&) = 0;

	virtual ~DtComida() = default;

};

#endif