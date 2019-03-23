
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


	bool operator==(DtFecha);
	bool operator<(const DtFecha&);
};


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


	bool operator==(DtFecha);
	bool operator<(const DtFecha&);
};

#endif