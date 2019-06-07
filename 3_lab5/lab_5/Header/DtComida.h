#ifndef DTCOMIDA_H
#define DTCOMIDA_H

#include <map>
#include <set>

using namespace std;
class DtMenu;

class DtComida {
protected:
	string codigo, descripcion;
	int precioTotal;

public:

	DtComida(string codigo, string descripcion, int precioTotal);

	//geters
	string getCodigo() const;
	string getDescripcion() const;
	int getPrecioTotal() const;
	virtual iostream& operator<<(std::ostream& out, DtComida* dt) = 0;

	virtual ~DtComida() = default;
	//Contructor por copia
	DtComida(const DtComida &comida);



};
#include "../Header/DtMenu.h"
#endif