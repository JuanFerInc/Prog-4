#ifndef DTCOMIDA_H
#define DTCOMIDA_H

#include <map>
#include <set>

using namespace std;
class DtMenu;

class DtComida {
private:
	string codigo, descripcion;
	int precioTotal;

public:
	DtComida(string codigo, string descripcion, int precioTotal)const;
	DtComida(const DtMenu &m);
	string getCodigo()const;
	string getDescripcion()const;
	int getPrecioTotal()const;
	virtual void print(std::ostream&) = 0;

	virtual ~DtComida() = default;

};
#include "../Header/DtMenu.h"
#endif