#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H	

#include <iostream>



using namespace std;

class DtEmpleado {
private:
	int nroEmpleado;
	string nombre;

public:
	DtEmpleado();
	DtEmpleado(string nombre, int nroEmp);
//geters
	int getNroEmpleado() const;
	string getNombre() const;

	//DtAsignacionMesa asignarAuto();


	friend std::ostream& operator<<(std::ostream& out, DtEmpleado *info);
	virtual void print(ostream& out);
};


#endif // !
