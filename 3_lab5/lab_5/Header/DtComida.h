#ifndef DTCOMIDA_H
#define DTCOMIDA_H

#include <map>
#include <set>





using namespace std;


class DtComida {
protected:
	string codigo, descripcion;
	int precioTotal;

public:
	DtComida() {};
	DtComida(string codigo, string descripcion, int precioTotal);

	//geters
	string getCodigo() const;
	string getDescripcion() const;
	int getPrecioTotal() const;

	
	//Contructor por copia
	DtComida(const DtComida &comida);

	friend std::ostream& operator<<(std::ostream& out, DtComida *info);
	virtual void print(ostream& out);
	bool operator<(const DtComida& d)const;
	
	virtual ~DtComida() = default;
};


#endif
