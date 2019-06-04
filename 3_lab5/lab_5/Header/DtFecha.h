#ifndef DTFECHA_H
#define DTFECHA_H	

class DtFecha {
private:
	int dia, mes, anio;

public: 
	DtFecha(const DtFecha &fecha);
	int getDia();
	int getMes();
	int getAnio();
};
#endif