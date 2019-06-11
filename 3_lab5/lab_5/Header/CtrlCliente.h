#ifndef CTRLCLIENTE_H
#define CTRLCLIENTE_H	

#include <iostream>
#include <map>

#include "../Header/ICliente.h"
#include "../Header/Cliente.h"
#include "../Header/Estado.h"
#include "../Header/DtCliente.h"


using namespace std;


class CtrlCliente: public ICliente{
private:
	static CtrlCliente* instancia;
	map<string, Cliente*> coleccionDeClientes;
	
	//Memoria del controlador del cliente a ser agregado
	string telefono;
	string nombre;
	DtDireccion direccion;


	CtrlCliente();
public:
	static CtrlCliente* getInstance();
	set<DtEstadoTerminado> verActualizacion(string tel);
	set<set<DtEstadoTerminado>> verTodasActualizaciones();
	
	//recuenda todo los datos ingresado
	DtCliente agregarCliente(string telefono, string nombre, DtDireccion dirrecion);
	void aceptarCliente();
	void cancelarCliente();


	//Venta a Domicilio
	bool existeCliente(string telefono);
	Cliente* pedirCliente();
	Cliente* pedirCliente(string telefono);
	
};

#endif