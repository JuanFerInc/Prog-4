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
void menu_admin(){
	int salir = 0;
	//using std::cin;
	//using std::cout;
	//print nosecuanto;
	while (!salir) {
		char comando;
		cout << endl;
		cout << "Bienvenido. Elija una opcion:" << endl;
		cout << "a) Dar de alta un producto" << endl;
		cout << "b) Dar de alta un cliente" << endl;
		cout << "c) Dar de alta un empleado" << endl;
		cout << "d) Asignar mozos a mesas" << endl;
		cout << "e) Empezar una venta a domicilio" << endl;
		cout << "f) Ver ventas de un mozo" << endl;
		cout << "g) Obtener informacion de un producto" << endl;
		cout << "h) Resumen de facturacion de un dia" << endl;
		cout << "i) Dar de baja un producto" << endl;
		cout << "j) Obtener informacion de un producto" << endl;
		cout << "k) Consultar actualizaciones de pedidos" << endl;
		cout << "$) Volver" << endl;

		cout << "Opcion: ";
		cin >> comando;
		Fabrica* fabriquita = Fabrica::getInstance();
		ICliente* interfazCliente = fabriquita->getICliente();
		IVenta * interfazVenta = fabriquita->getIVenta();
		IProducto* interfazProducto = fabriquita->getIProducto();
		IEmpleado* interfazEmpleado = fabriquita->getIEmpleado();

		
		char seguro;
		if (comando == 'a') {
			bool quieroSeguirAgregando = true;
			while (quieroSeguirAgregando) {
				bool hayP = interfazProducto->masDeUnProducto();
				if (hayP) {
					cout << "Es un producto o un menu amigazo [p/m]" << endl;
					char temp;
					cin >> temp;
					if (temp == 'p') {
						hayP = false;
					}
					else if (temp != 'm') {
						cout << "Debe elegir menu (m) o producto (p)" << endl;
						throw('x');
					}
				}
				string descripcion, codigo;
				cout << "Ingrese la descripcion si es tan amable" << endl;
				cin >> descripcion;
				cout << "Ingrese el codigo" << endl;
				cin >> codigo;
				
				if (!hayP) {
					int precio;
					cout << "Ingrese el precio" << endl;
					cin >> precio;
					interfazProducto->agregarProducto(codigo, descripcion, precio);
					cout << "Estas 100% segurisisimo [y/n]?" << endl;
					cin >> seguro;
					if (seguro == 'y')
						interfazProducto->aceptarAltaProducto();
					else if (seguro == 'n')
						interfazProducto->cancelarAltaProducto();
					else {
						cout << "Los comandos validos son [y/n], mas cuidado la proima maquina" << endl;
						throw('x');
					}
				
				}else {
					set<DtProducto> cosas = interfazProducto->agregarMenu(codigo, descripcion);
					set<DtProducto>::iterator iter;
					cout << "Estos son los productos disponibles: " << endl;
					for (iter = cosas.begin(); iter != cosas.end; iter++) {
						DtProducto dt = *iter;
						cout << &dt << endl;
					}
					while (!hayP) {
						string codprod;
						int cantidad;
						cout << "Ingrese el codigo del producto" << endl;
						cin >> codprod;
						cout << "Ingrese la cantidad" << endl;
						cin >> cantidad;
						interfazProducto->agregarProductoMenu(codprod, cantidad);
						cout << "Deseas continuar buddy? [y/n]";
						cin >> seguro;
						if (seguro == 'n')
							hayP = false;
						else if (seguro != 'y')
							throw('x');
					}
					cout << "Estas 100% segurisisimo [y/n]?" << endl;
					cin >> seguro;
					if (seguro == 'y')
						interfazProducto->aceptarAltaMenu();
					else if (seguro == 'n')
						interfazProducto->cancelarAltaMenu();
					else {
						cout << "Los comandos validos son [y/n], mas cuidado la proima maquina" << endl;
						throw('x');
					}
				}

			}
			cout << "Desea continuar? [Si = 0]" << endl;
			cin >> salir;
			cout << "Que paso amiguito?" << endl;
		}else if(comando == 'b'){
			string tel, nombre, calle, numero, ady, ed, eddy;
			
			cout << "Ingrese el telefono" << endl;
			cin >> tel;
			cout << "Ingrese el nombre" << endl;
			cin >> nombre;
			cout << "Ingrese nombre de la calle" << endl;
			cin >> calle;
			cout << "Ingrese el numero" << endl;
			cin >> numero;
			cout << "Calles esquinas" << endl;
			cin >> ady;
			cout << "Tendrias la amabilidad de decirme si tu domicilio es una casa o un apartamento [c/a]" << endl;
			cin >> seguro;
			if (seguro == 'c') {
				DtCliente clientepepe = interfazCliente->agregarCliente(tel,nombre, DtDireccion(numero,calle,ady));
				cout << &clientepepe << endl;
			}
			else if (seguro == 'a') {
				cout << "Ingrese nombre del edificio colega" << endl;
				cin >> ed;
				cout << "Ingerese el numero de apartamento" << endl;
				cin >> eddy;
				DtCliente clientepepe = interfazCliente->agregarCliente(tel,nombre,DtApartamento(ed, eddy, calle, ady,numero));
				cout << &clientepepe << endl;
			}
			else {
				cout << "ingrese una casa o un apartamento [a/m]" << endl;
				throw('x');
			}
			cout << "brodi, estas seguro?[y/n]" << endl;
			cin >> seguro;
			if (seguro == 'y') {
				interfazCliente->aceptarCliente();
			}
			else if (seguro == 'n') {
				interfazCliente->cancelarCliente();
			}
			else {
				cout << "si o no flaco[y/n]" << endl;
				throw('x');
			}
		} else if (comando == 'c') {
			bool seguir = true;
			while (seguir) {
				cout << "Desea ingresar un mozo(m) o un delivery (d) " << endl;
				cin >> seguro;
				string x;
				if (seguro == 'm') {
					cout << "Ingrese el nombre del mozo " << endl;
					cin >> x;
					interfazEmpleado->agregarMozo(x);
				}else if  (seguro == 'd') {
					cout << "Ingrese el nombre del delivery" << endl;
					cin >> x;
					interfazEmpleado->agregarDelivery(x);
					cout << "Los transportes disponible son: Pie (p), Bicicleta (b) o Motocicleta (m). Elija uno!" << endl;
					cin >> seguro;
					if (seguro == 'p') {
						interfazEmpleado->elegirVehiculo('p');
					}
					else if (seguro == 'b') {
						interfazEmpleado->elegirVehiculo('b');
					}
					else if (seguro== 'm') {
						interfazEmpleado->elegirVehiculo('m');
					} else {
						cout << "Las opciones posibles son: Pie (p), Bicicleta (b) o Motocicleta (m)" << endl;
						throw('x');
					}
				} else {
					cout << "tigre, ingrese un mozo(m) o delivery (d)" << endl;
					throw('x');
				}


			}
		}
		

		























	}//while
}//menuadmin