#include "../Header/DtDireccion.h"


class DtApartamento : public DtDireccion {
private:
	string nombreEdificio, numeroApartamento;

public:
	//Contructor por copia
	DtApartamento(const DtApartamento &apart);
	//geters
	string getNombreEdificio();
	string getNumeroApartamento();

};