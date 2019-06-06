#ifndef DTHORA_H
#define DTHORA_H	

class DtHora {
private:
	int minuto, hora;

public:
	DtHora(const DtHora &hora);
//geters

	int getMinuto();
	int getHora();

//otras

	bool operator<(const DtHora& a);
};
#endif