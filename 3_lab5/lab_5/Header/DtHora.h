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
	DtHora(const DtHora &hora);
//geters

	int getMinuto();
	int getHora();

//otras
	void print(ostream& out);
	bool operator<(const DtHora& a);
	DtHora operator=(const DtHora& a);
};
#endif