#include "../Header/Formulario.h"
#include "../Header/Fabrica.h"
#include <iostream>
#include <set>
#include "../Header/DtProducto.h"
#include "../Header/DtCliente.h"
#include "../Header/DtDireccion.h"
#include "../Header/DtApartamento.h"


using namespace std;
//Los menus individuales tiran error x al menu posta
void menuPosta() {


	int salir = 0;
	while (!salir) {
		char comando;
		cout << endl;
		cout << "Bienvenido a lo de Pepe, elija una opcion:" << endl;
		cout << "1) Administrador" << endl;
		cout << "2) Mozo" << endl;
		cout << "3) Repartidor" << endl;
		cout << "4) Cliente" << endl;
		cout << "5) Cargar datos de prueba" << endl;
		cout << "6) Salir" << endl;


		cout << "Opcion: ";
		cin >> comando;


		if (comando == '1') {
			menu_admin();
		}
		else if (comando == '2') {
			menu_mozo();
		}
		else if (comando == '3') {
			menu_repartidor();
		}
		else if (comando == '4') {
			menu_cliente();
		}
		else if (comando == '5') {
			cargar_datos();
		}
		else if (comando == '6') {
			salir = 982;
		}
	}
		
}//menuPosta


void menuRepartidor() {

	Fabrica* factory = Fabrica::getInstance();
	IVenta* rep = factory->getIVenta();
	cout << "Ingrese el numero de venta" << endl;
	int num;
	char x;
	cin >> num;
	cout << "Desea actualizar el estado (a) o cancelar (c)" << endl;
	cin >> x;
	if (x == 'a') {
		rep->actualizarVenta();						//No tiene por qué ser en venta, hay que verlo    //Hay que tirar error aca
		cout << "El estado ha sido actualizado" << endl;
	}
	else if (x == 'c') {
		rep->cancelarPedido(num);					//Hay que tirar error aca
		cout << "El pedido ha sido cancelado" << endl;
	}
}
//Hay dos funciones de ver actualizaciones (en venta y en cliente)
void menuCliente() {
	cout << "Ingrese el numero de telefono" << endl;
	string tel;
	cin >> tel;
	Fabrica* factory = Fabrica::getInstance();
	ICliente* cliente = factory->getICliente();
	set<DtEstadoTerminado> printer = cliente->verActualizacion(tel);			//Esto tira error?
	set<DtEstadoTerminado>::iterator iter;
	for (iter = printer.begin(); iter != printer.end(); iter++) {
		DtEstadoTerminado temp = *iter;
		cout << temp << endl;
	}
}

void menuMozo() {
	int salir = 0;
	while (!salir) {
		char comando;
		cout << endl;
		cout << "Elija una opcion:" << endl;
		cout << "a) Iniciar venta en una mesa" << endl;
		cout << "b) Agregar producto a venta" << endl;
		cout << "c) Quitar producto de venta" << endl;
		cout << "d) Facturar una venta" << endl;
		cout << "e) Volver" << endl;


		cout << "Opcion: ";
		cin >> comando;


		if (comando == 'a') {
			cout << "Por favor ingrese su numero de empleado" << endl;
			int num;
			cin >> num;
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			set<int> printer = ventas->mesasAsignadas(num);
			set<int>::iterator iter;
			for (iter = printer.begin(); iter != printer.end(); iter++) {
				int i = *iter;
				cout << i << endl;
			}


			bool quiereAgregar = true;
			while (quiereAgregar) {
				cout << "Ingrese un numero de mesa" cout << endl;
				cin >> num;
				ventas->agregarMesaAVenta(num);
				cout << "Quiere seguir agregando? [y/n]" << endl;
				char cont;
				cin >> cont;
				if (cont == 'y') {
					quiereAgregar = true;
				}
				else if (cont == 'n') {
					quiereAgregar = false;
				}
				else {
					cout << "No reconocido" << endl;
					throw ('x');
				}
			}
			set<int> printer = ventas->mostrarMesasSeleccionadas();
			for (iter = printer.begin(); iter != printer.end(); iter++) {
				int i = *iter;
				cout << i << endl;
			}
			cout << "Desea confirmar?" << endl;
			char cont;
			cin >> cont;
			if (cont == 'y') {
				ventas->confirmarVentaEnMesas();
			}
			else if (cont == 'n') {
				ventas->descartarVentasEnMesa();
			}
			else {
				cout << "No reconocido" << endl;
				throw ('x');
			}
		}
		else if (comando == 'b') {
			
		}
		else if (comando == 'c') {
			
		}

	}
}
