#ifndef DTHORA_H
#define DTHORA_H	

#include <iostream>
#include <string>

using namespace std;

class DtHora {
private:
	int minuto, hora;

public:
	DtHora();
	DtHora(int minuto, int hora);

	DtHora(const DtHora &hora);
//geters

	int getMinuto();
	int getHora();

//otras
	void print(ostream& out);
	friend ostream& operator<<(ostream& out, DtHora*info);
	bool operator<(const DtHora& a);
	DtHora operator=(const DtHora& a);
	friend std::ostream& operator<<(std::ostream& out, DtHora*info);
};
#endif