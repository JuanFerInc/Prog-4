#include "../Header/Formulario.h"
#include "../Header/Fabrica.h"
#include <iostream>
#include <set>
#include "../Header/DtProducto.h"
#include "../Header/DtCliente.h"
#include "../Header/DtDireccion.h"
#include "../Header/DtApartamento.h"
#include "../Header/DtAsignacionMesa.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFacturaDomicilio.h"
#include "../Header/DtFacturaResumen.h"

using namespace std;
//Los menus individuales tiran error x al menu posta
void menu_admin(){
	int salir = 0;
	while (!salir) {
		char comando;
		cout << endl;
		cout << "Bienvenido. Elija una opcion:" << endl;
		cout << "a) Dar de alta un producto" << endl;
		cout << "b) Dar de alta un cliente" << endl;
		cout << "c) Dar de alta un empleado" << endl;
		cout << "d) Asignar mozos a mesas" << endl;
		cout << "e) Empezar una venta a domicilio" << endl;
		//cout << "f) Ver ventas de un mozo" << endl;
		cout << "f) Obtener informacion de un producto" << endl;
		cout << "g) Resumen de facturacion de un dia" << endl;
		cout << "h) Dar de baja un producto" << endl;
		//cout << "i) Obtener informacion de un producto" << endl;
		cout << "i) Consultar actualizaciones de pedidos" << endl;
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
						cambiar firma de funcion elegirvehiculo lcdtm;
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
				cout << "Desea confirmar [y/n]" << endl;
				cin >> seguro;
				if (seguro == 'y') {
					interfazEmpleado->confirmarEmpleado();
				} else if (seguro == 'n') {
					interfazEmpleado->cancelarEmpleado();
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}

			}
		}
		else if (comando == 'd') {
		DtAsignacionMesa dtam = interfazEmpleado->asignarAuto();
		cout << " " << &dtam << endl;
		} else if (comando == 'e') {
			cout << "Ingrese el telefono" << endl;
			cin >> seguro;
			bool existe = interfazVenta->iniciarVentaDomicilio(seguro);
			if (!existe) {
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
					DtCliente clientepepe = interfazCliente->agregarCliente(tel, nombre, DtDireccion(numero, calle, ady));
					cout << &clientepepe << endl;
				}
				else if (seguro == 'a') {
					cout << "Ingrese nombre del edificio colega" << endl;
					cin >> ed;
					cout << "Ingerese el numero de apartamento" << endl;
					cin >> eddy;
					DtCliente clientepepe = interfazCliente->agregarCliente(tel, nombre, DtApartamento(ed, eddy, calle, ady, numero));
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
			}
			set<DtComida> dtc = interfazProducto->listaDeComidaDisponible();
			set<DtComida>::iterator iter;
			for (iter = dtc.begin(); iter != dtc.end(); iter++) {
				cout << " " << &(*iter) << endl;
			}
			bool nosalir = true;
			string cod;
			int cant;
			while (nosalir) {
				cout << "Ingrese codigo" << endl;
				cin >> cod;
				cout << "ingrese la cantidad" << endl;
				cin >> cant;
				interfazVenta->seleccionarComida(cod, cant);
				cout << "Desea seguir agregando comidas [y/n]" << endl;
				cin >> seguro;
				if (seguro == 'n') {
					nosalir = false;
				} else if (seguro !='y') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
			}
			cout << "Deseas solicitar un repartidor[y/n]" << endl;
			cin >> seguro;
			if (seguro == 'y') {
				set<DtDelivery> dtc = interfazEmpleado->listarRepartidores();
				set<DtDelivery>::iterator iter;
				for (iter = dtc.begin(); iter != dtc.end(); iter++) {
					cout << " " << &(*iter) << endl;
				}
				string repartidor;
				cout << "Elija un repartidor" << endl;
				cin >> repartidor;
				interfazEmpleado->seleccionarRepartidor(repartidor);
			}
			else if (seguro != 'n') {
				cout << "Por favor ingrese los datos pedidos" << endl;
				throw('x');
			}
			cout << "Desea confirmar [y/n]" << endl;
			cin >> seguro;
			if (seguro == 'y') {
				interfazVenta->confirmarVentaDomicilio();
				int des;
				cout << "Ingrese el descuento, en caso de no aplicar ingrese(0)" << endl;
				cin >> des;
				DtFacturaDomicilio dfd = interfazVenta->facturarVentaDomicilio(des);
				cout << " " << &dfd << endl;
			}
			else if (seguro == 'n') {
				interfazVenta->cancelarVentaDomicilio();
			}
			else {
				cout << "Por favor ingrese los datos pedidos" << endl;
				throw('x');
			}
		}
		else if (comando == 'f') {
			set<DtComida> dtc = interfazProducto->listaDeComidaDisponible();
			set<DtComida>::iterator iter;
			for (iter = dtc.begin(); iter != dtc.end(); iter++) {
				cout << " " << &(*iter) << endl;
			}
			bool consultar = true;
			bool esta = true;
			string cod;
			cout << "Que comida desea consultar" << endl;
			cin >> cod;
			while (consultar) {
				esta = interfazProducto->existeComida(cod);
				if (esta) {
					DtComida dt = interfazProducto->ingresarCodigo(cod);
				}
				cout << "Desea seguir consultando[y/n]" << endl;
				cin >> seguro;
				if (seguro == 'n') {
					consultar = false;
				}
				else if (seguro != 'y') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}	
			}
		}
		else if (comando == 'g') {
		int d,m,a;
		cout << "ingrese el dia " << endl;
		cin >> d;
		cout << "ingrese el mes" << endl;
		cin >> m;
		cout << "ingrese el anio" << endl;
		cin >> a;
		if (d > 0) {
			if (d < 32) {
				if (m > 0) {
					if (m < 13) {
						if (a >= 0) {
							DtFacturaResumen dfr = interfazVenta->resumenDelDia(d, m, a);
							cout << " " << &dfr << endl;
						}
						else {
							cout << "Por favor ingrese un anio no negativos" << endl;
							throw('x');
						}
					}
					else {
						cout << "Por favor ingrese un mes menor a 13" << endl;
						throw('x');
					}
				}
				else {
					cout << "Por favor ingrese un mes no negativo" << endl;
					throw('x');
				}
			}
			else {
				cout << "Por favor ingrese un dia menor a 32" << endl;
				throw('x');
			}
		}
		else {
			cout << "Por favor ingrese un dia no negativo" << endl;
			throw('x');
		}
		}
		else if (comando == 'h') {
			set<DtComida> dtc = interfazProducto->listaDeComidaDisponible();
			set<DtComida>::iterator iter;
			for (iter = dtc.begin(); iter != dtc.end(); iter++) {
				cout << " " << &(*iter) << endl;
			}
			cout << "Ingrese el codigo deseado" << endl;
			string cod;
			cin >> cod;
			interfazProducto->ingresarCodigo(cod);
			cout << "Desea confirmar [y/n] " << endl;
			cin >> seguro;
			if (seguro == 'y') {
				interfazProducto->confirmarBaja();
			}
			else if (seguro == 'n') {
				interfazProducto->cancelarBaja();
			}
			else {
				cout << "Por favor ingrese los datos pedidos" << endl;
				throw('x');
			}
		}
		else if (comando == 'i') {
			set<DtEstadoTerminado> act = interfazCliente->consultarActualizaciones();
			cout << " " << &act << endl;
		}
		else if (comando == '$') {
		salir = 21; //2121212121 twenty one tueni wuan
}
		
}//while


}//menuadmin