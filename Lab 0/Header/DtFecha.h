#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha {
private:
	int d, m, a;
public:
	//Constructores
	DtFecha();
	DtFecha(int, int, int);
	DtFecha(const DtFecha&);

	//getters
	int getDia();
	int getMes();
	int getAnio();

	//Otras

	DtFecha operator=(DtFecha);
	bool operator==(DtFecha);
	bool operator<(const DtFecha&);
};

#endif