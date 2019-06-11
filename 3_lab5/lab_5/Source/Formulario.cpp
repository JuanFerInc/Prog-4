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
#include "../Header/TipoTransporte.h"


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
					cout << "Es un producto o un menu [p/m]" << endl;
					char temp;
					cin >> temp;
					if (temp == 'p') {
						hayP = false;
					}
					else if (temp != 'm') {
						cout << "Por favor ingrese los datos pedidos" << endl;
						throw('x');
					}
				}
				string descripcion, codigo;
				cout << "Ingrese la descripcion " << endl;
				cin >> descripcion;
				cout << "Ingrese el codigo" << endl;
				cin >> codigo;
				
				if (!hayP) {
					int precio;
					cout << "Ingrese el precio" << endl;
					cin >> precio;
					interfazProducto->agregarProducto(codigo, descripcion, precio);
					cout << "Confirmar [y/n]?" << endl;
					cin >> seguro;
					if (seguro == 'y')
						interfazProducto->aceptarAltaProducto();
					else if (seguro == 'n')
						interfazProducto->cancelarAltaProducto();
					else {
						cout << "Por favor ingrese los datos pedidos" << endl;
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
						cout << "Deseas continuar [y/n]";
						cin >> seguro;
						if (seguro == 'n')
							hayP = false;
						else if (seguro != 'y')
							throw('x');
					}
					cout << "Confirmar [y/n]?" << endl;
					cin >> seguro;
					if (seguro == 'y')
						interfazProducto->aceptarAltaMenu();
					else if (seguro == 'n')
						interfazProducto->cancelarAltaMenu();
					else {
						cout << "Por favor ingrese los datos pedidos" << endl;
						throw('x');
					}
				}

			}
			cout << "Desea continuar [Si = 0]" << endl;
			cin >> salir;
			//cout << "Que paso amiguito?" << endl;
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
			cout << " casa o apartamento [c/a]" << endl;
			cin >> seguro;
			if (seguro == 'c') {
				DtCliente clientepepe = interfazCliente->agregarCliente(tel,nombre, DtDireccion(numero,calle,ady));
				cout << &clientepepe << endl;
			}
			else if (seguro == 'a') {
				cout << "Ingrese nombre del edificio " << endl;
				cin >> ed;
				cout << "Ingrese el numero de apartamento" << endl;
				cin >> eddy;
				DtCliente clientepepe = interfazCliente->agregarCliente(tel,nombre,DtApartamento(ed, eddy, calle, ady,numero));
				cout << &clientepepe << endl;
			}
			else {
				cout << "Por favor ingrese los datos pedidos" << endl;
				throw('x');
			}
			cout << "confirmar[y/n]" << endl;
			cin >> seguro;
			if (seguro == 'y') {
				interfazCliente->aceptarCliente();
			}
			else if (seguro == 'n') {
				interfazCliente->cancelarCliente();
			}
			else {
				cout << "Por favor ingrese los datos pedidos" << endl;
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
						
						interfazEmpleado->elegirVehiculo(PIE);
					}
					else if (seguro == 'b') {
						//cambiar firma de funcion elegirvehiculo lcdtm;
						interfazEmpleado->elegirVehiculo(BICI);
					}
					else if (seguro== 'm') {
						interfazEmpleado->elegirVehiculo(MOTO);
					} else {
						cout << "Por favor ingrese los datos pedidos" << endl;
						throw('x');
					}
				} else {
					cout << "Por favor ingrese los datos pedidos" << endl;
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
		set<DtAsignacionMesa> dtam = interfazEmpleado->asignarAuto();
		set<DtAsignacionMesa>::iterator iter;
		for (iter = dtam.begin(); iter != dtam.end(); iter++) {
			cout << " " << &(*iter) << endl;
		}
		} else if (comando == 'e') {
			cout << "Ingrese el telefono" << endl;
			string telef;
			cin >> telef;
			bool existe = interfazVenta->iniciarVentaADomicilio(telef);
			if (!existe) {
				string nombre, calle, numero, ady, ed, eddy;

				//cout << "Ingrese el telefono" << endl;
				//cin >> tel;
				cout << "Ingrese el nombre" << endl;
				cin >> nombre;
				cout << "Ingrese nombre de la calle" << endl;
				cin >> calle;
				cout << "Ingrese el numero" << endl;
				cin >> numero;
				cout << "Calles esquinas" << endl;
				cin >> ady;
				cout << "casa o apartamento [c/a]" << endl;
				cin >> seguro;
				if (seguro == 'c') {
					DtCliente clientepepe = interfazCliente->agregarCliente(telef, nombre, DtDireccion(numero, calle, ady));
					cout << &clientepepe << endl;
				}
				else if (seguro == 'a') {
					cout << "Ingrese nombre del edificio" << endl;
					cin >> ed;
					cout << "Ingrese el numero de apartamento" << endl;
					cin >> eddy;
					DtCliente clientepepe = interfazCliente->agregarCliente(telef, nombre, DtApartamento(ed, eddy, calle, ady, numero));
					cout << &clientepepe << endl;
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
				cout << "confirmar[y/n]" << endl;
				cin >> seguro;
				if (seguro == 'y') {
					interfazCliente->aceptarCliente();
				}
				else if (seguro == 'n') {
					interfazCliente->cancelarCliente();
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
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
			bool quiereRepartidor = false;
			if (seguro == 'y') {
				quiereRepartidor = true;
				set<DtDelivery> dtc = interfazEmpleado->darRepartidores();
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
				interfazVenta->confirmarVentaADomicilio();
				int des;
				cout << "Ingrese el descuento, en caso de no aplicar ingrese 0" << endl;
				cin >> des;
				if (quiereRepartidor) {
					DtFacturaDomicilio dfd = interfazVenta->facturarVentaADomicilio(des);
					cout << " " << &dfd << endl;
				}
				else {
					DtFactura dfd = interfazVenta->facturarVentaADomicilioSinDelivery(des);
					cout << " " << &dfd << endl;
				}
			}
			else if (seguro == 'n') {
				interfazVenta->cancelarVentaADomicilio();
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
					DtComida dt = interfazProducto->ingresarCodigo(cod);//juan lo tiene bien
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
		string telefono;
		cout << "Ingrese telefono" << endl;
		cin >> telefono;
			set<DtEstadoTerminado> act = interfazCliente->verActualizacion(telefono);
			set<DtEstadoTerminado>::iterator iter;
			for (iter = act.begin(); iter != act.end(); iter++) {
				cout << " " << &(*iter) << endl;
			}
		}
		else if (comando == '$') {
		salir = 21; //2121212121 twenty one tueni wuan
}
		
}//while


}//menuadmin


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
		cout << &temp << endl;
	}
}//menucliente

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
				cout << "Ingrese un numero de mesa"  << endl;
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
					cout << "Por favor ingrese los datos pedidos" << endl;
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
				cout << "Por favor ingrese los datos pedidos" << endl;
				throw ('x');
			}
		}
		else if (comando == 'b') {
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			IProducto* productos = factory->getIProducto();
			int nromesa;
			cout << "Ingrese el numero de mesa" << endl;
			cin >> nromesa;
			ventas->ingresarNroMesa(nromesa);
			set<DtComida> dtc = productos->listaDeComidaDisponible();
			set<DtComida>::iterator iter;
			for (iter = dtc.begin(); iter != dtc.end(); iter++) {
				cout << " " << &(*iter) << endl; 
			}
			bool seguir = true;
			string cod;
			int cant;
			char seguro;
			while (seguir) {
				cout << "Ingrese el codigo de la comida a agregar a la venta" << endl;
				cin >> cod;
				cout << "Ingrese la cantidad" << endl;
				cin >> cant;
				ventas->seleccionarComida(cod, cant);
				cout << "Desea confirmar[y/n]" << endl;
				cin >> seguro;
				if (seguro == 'y') {
					bool hay = ventas->existeComidaEnVenta();
					if (hay) {
						ventas->incrementarCantidad();
					}
					else {
						ventas->agregarPorPrimeraVez();
					}
				}
				else if (seguro =='n') {
					ventas->descartarAgregado();
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw ('x');
				}
				cout << "Desea seguir agregando[y/n]" << endl;
				cin >> seguro;
				if (seguro == 'n') {
					seguir = false;
				}
				else if (seguro !='y') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw ('x');
				}
			}
			ventas->liberarnroMesa();
		}
		else if (comando == 'c') {
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			IProducto* productos = factory->getIProducto();
			cout << "Ingrese el numero de mesa" << endl;
			int nro;
			cin >> nro;
			set <DtComida> comidas = ventas->productosEnVentaEnMesa(nro);
			set<DtComida>::iterator iter;
			for (iter = comidas.begin(); iter != comidas.end(); iter++) {
				cout << " " << &(*iter) << endl;
			}
			bool seguirQuitando = true;
			string cod;
			char seguro;
			int cant;
			while (seguirQuitando) {
				cout << "Ingrese el codigo de la comida a quitar" << endl;
				cin >> cod;
				cout << "ingrese la cantidad a quitar" << endl;
				cin >> cant;
				ventas->seleccionarComida(cod, cant);
				cout << "Desea confirmar" << endl;
				cin >> seguro;
				if (seguro == 'y') {
					bool mayor = ventas->cantidadEsMayor();
					if (mayor) {
						ventas->disminuirCantidad();
					}
					else {
						ventas->eliminarComidaDeVenta();
					}
				}
				else if (seguro == 'n') {
					ventas->descartarEliminacion();
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw ('x');
				}
				cout << "Desea seguir quitando" << endl;
				cin >> seguro;
			}
			ventas->liberarnroMesa();
		}
		else if (comando == 'd') {
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			string nromesa;
			int des;
			cout << "Ingrese el numero de mesa" << endl;
			cin >> nromesa;
			cout << "ingrese el descuento, en caso de no aplicar descuento ingrese (0)" << endl;
			cin >> des;
			DtFactura res = ventas->generarFactura(nromesa, des);
			cout << " " << &res << endl;
		}
		else if (comando == 'e') {
			salir = 21;
		}

	}
} //menumozo
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
			menuMozo();
		}
		else if (comando == '3') {
			menuRepartidor();
		}
		else if (comando == '4') {
			menuCliente();
		}
		else if (comando == '5') {
			cargarDatos();
		}
		else if (comando == '6') {
			salir = 21;
		}
	}

}//menuPosta
