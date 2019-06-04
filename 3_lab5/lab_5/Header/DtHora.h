#ifndef DTHORA_H
#define DTHORA_H	

class DtHora {
private:
	int minuto, hora;

public:
	DtHora(const DtHora &hora);
	int getMinuto();
	int getHora();
};
#endif