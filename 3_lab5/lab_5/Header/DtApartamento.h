#include "../Header/DtDireccion.h"


class DtApartamento : public DtDireccion {
private:
	string nombreEdificio, numeroApartamento;

public:
	//geters
	string getNombreEdificio();
	string getNumeroApartamento();

};