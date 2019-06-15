#include "../Header/Formulario.h"
#include "../Header/Fabrica.h"
#include <iostream>
#include <string>
#include <set>
#include "../Header/DtProducto.h"
#include "../Header/DtCliente.h"
#include "../Header/DtDireccion.h"
#include "../Header/DtApartamento.h"
#include "../Header/DtAsignacionMesa.h"
#include "../Header/DtDelivery.h"
#include "../Header/DtFacturaDomicilio.h"
#include "../Header/DtFacturaResumen.h"
#include "../Header/DtMenuVenta.h"
#include "../Header/DtComida.h"
#include "../Header/TipoTransporte.h"
#include "../Header/DtProductoVenta.h"
#include "../Header/DtEstadoTerminado.h"
#include "../Header/DtFactura.h"


using namespace std;

bool mesasAsignadas = false;

//Los menus individuales tiran error x al menu posta
void menu_admin(){
	int salir = 0;
	while (!salir) {
		char comando;

	
		system("CLS");//limpia la pantalla
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
		cout << "x) Volver" << endl;

		cout << "Opcion: ";
		cin >> comando;
		Fabrica* fabriquita = Fabrica::getInstance();
		ICliente* interfazCliente = fabriquita->getICliente();
		IVenta * interfazVenta = fabriquita->getIVenta();
		IProducto* interfazProducto = fabriquita->getIProducto();
		IEmpleado* interfazEmpleado = fabriquita->getIEmpleado();

		
		char seguro;
		bool quieroSeguirAgregando = true;
		bool agregar_Producto = true;

		if (comando == 'a') {
			while (quieroSeguirAgregando) {
				bool hayP = interfazProducto->masDeUnProducto();
				if (hayP) {
					system("CLS");//limpia la pantalla
					cout << "Es un producto o un menu [p/m]" << endl;
					char temp;
					cin >> temp;
					if (temp == 'p') {
						agregar_Producto = true;
					}
					else if (temp == 'm') {
						agregar_Producto = false;
					}
					else if (temp != 'm') {
						cout << "Por favor ingrese los datos pedidos" << endl;
						throw('x');
					}
				}
				else {
					agregar_Producto = true;
				}
				string descripcion, codigo;
				system("CLS");//limpia la pantalla
				cin.ignore();//ignore el ENTER precinado en el menu
				cout << "Ingrese la descripcion " << endl;
				getline(cin, descripcion);
				
				cout << "Ingrese el codigo" << endl;
				getline(cin, codigo);
				

				if (agregar_Producto) {
					int precio;
					cout << "Ingrese el precio" << endl;
					cin >> precio;
					interfazProducto->agregarProducto(codigo, descripcion, precio);
					cout << "Confirmar [y/n]?" << endl;
					cin >> seguro;
					if (seguro == 'y') {
						if (interfazProducto->existeComida(codigo)) {
							cout << "Ya existe una comida con ese Codigo" << endl;
							interfazProducto->cancelarAltaProducto();
							throw ('x');
						}
						else {
							interfazProducto->aceptarAltaProducto();
						}
						
					}
					else if (seguro == 'n')
						interfazProducto->cancelarAltaProducto();
					else {
						cout << "Por favor ingrese los datos pedidos" << endl;
						throw('x');
					}
				
				}else {
					set<DtProducto*> cosas = interfazProducto->agregarMenu(codigo, descripcion);
					set<DtProducto*>::iterator iter;
					cout << "Estos son los productos disponibles: " << endl;
					for (iter = cosas.begin(); iter != cosas.end(); iter++) {
						DtProducto *dt = *iter;
						cout << dt << endl;
					}
					bool continuar_Menu = true;
					while (continuar_Menu) {
						string codprod;
						int cantidad;
						cout << "Ingrese el codigo del producto" << endl;
						getline(cin, codprod);
						cout << "Ingrese la cantidad" << endl;
						cin >> cantidad;
						interfazProducto->agregarProductoMenu(codprod, cantidad);
						cout << "Deseas continuar agregando productos? [y/n]" << endl;
						cin >> seguro;
						cin.ignore();//ignore el ENTER precinado en el menu
						if (seguro == 'n')
							continuar_Menu = false;
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
				char continuar;
				cout << "Quiere Continuar Agregando Comida? [y/n]?" << endl;
				cin >> continuar;
				cin.ignore();//ignore el ENTER precinado en el menu
				if (continuar == 'y')
					quieroSeguirAgregando = true;
				else if (continuar == 'n')
					quieroSeguirAgregando = false;
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
			}
			//cout << "Desea continuar [Si = 0]" << endl;
			//cin >> salir;
		}
		else if(comando == 'b'){
			string tel, nombre, calle, numero, ady, ed, eddy;
			system("CLS");//limpia la pantalla
			cin.ignore();//ignore el ENTER precinado en el menu
			cout << "Ingrese el telefono" << endl;
			getline(cin, tel);
			if (interfazCliente->existeCliente(tel)) {
				throw(10);
			}
			cout << "Ingrese el nombre" << endl;
			getline(cin, nombre);
			cout << "Ingrese nombre de la calle" << endl;
			getline(cin, calle );
			cout << "Ingrese el numero" << endl;
			getline(cin, numero);
			cout << "Calles esquinas" << endl;
			getline(cin, ady );
			cout << "casa o apartamento [c/a]" << endl;
			cin >> seguro;
			if (seguro == 'c') {
                DtDireccion* direccionDePepe = new DtDireccion(numero,calle,ady);
				DtCliente *clientepepe = interfazCliente->agregarCliente(tel,nombre, direccionDePepe);
                delete direccionDePepe;
				cout << clientepepe << endl;
				delete clientepepe;
			}
			else if (seguro == 'a') {
		
				cin.ignore();//ignore el ENTER precinado en el menu
				cout << "Ingrese nombre del edificio " << endl;
				getline(cin, ed);
				cout << "Ingrese el numero de apartamento" << endl;
				getline(cin, eddy);
                DtApartamento* apartamento = new DtApartamento(ed, eddy, calle, ady,numero);
				DtCliente *clientepepe = interfazCliente->agregarCliente(tel,nombre,apartamento );
				cout << clientepepe << endl;
				delete clientepepe;

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
		else if (comando == 'c') {
			bool seguir = true;
			while (seguir) {
				system("CLS");//limpia la pantalla
				cin.ignore();//ignore el ENTER precinado en el menu
				cout << "Desea ingresar un mozo(m) o un delivery (d) " << endl;
				cin >> seguro;
				string x;
				if (seguro == 'm') {
					cin.ignore();//ignore el ENTER precinado en el menu
					cout << "Ingrese el nombre del mozo " << endl;
					getline(cin, x);
					interfazEmpleado->agregarMozo(x);
				}else if  (seguro == 'd') {
					cin.ignore();//ignore el ENTER precinado en el menu
					cout << "Ingrese el nombre del delivery" << endl;
					getline(cin, x);
					interfazEmpleado->agregarDelivery(x);
					cout << "Los transportes disponible son: Pie (p), Bicicleta (b) o Motocicleta (m). Elija uno!" << endl;
					cin >> seguro;
					if (seguro == 'p') {
						interfazEmpleado->elegirVehiculo(PIE);
					}
					else if (seguro == 'b') {
						
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
				cout << "Desea agregar otro Empleado? [y/n]" << endl;
				cin >> seguro;
				if (seguro == 'n') {
					seguir = false;
				}
				else if (seguro != 'y') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
			}
			
		}
		else if (comando == 'd') {
		set<DtAsignacionMesa*> dtam = interfazEmpleado->asignarAuto();
		set<DtAsignacionMesa*>::iterator iter;
		for (iter = dtam.begin(); iter != dtam.end(); iter++) {
			cout << "" << (*iter) << endl;
		}
		mesasAsignadas = true;
		system("pause");
		} 
		else if (comando == 'e') {
			bool cliente_ingreaso = true;
			cin.ignore();//ignore el ENTER precinado en el menu
			cout << "Ingrese el telefono" << endl;
			string telef;
			getline(cin, telef);
			bool existe = interfazVenta->iniciarVentaADomicilio(telef);
			if (!existe) {
				string nombre, calle, numero, ady, ed, eddy;

				//cout << "Ingrese el telefono" << endl;
				//cin >> tel;
				cout << "Ingrese el nombre" << endl;
				getline(cin, nombre);
				cout << "Ingrese nombre de la calle" << endl;
				getline(cin, calle);
				cout << "Ingrese el numero" << endl;
				getline(cin, numero);
				cout << "Calles esquinas" << endl;
				getline(cin, ady);
				cout << "casa o apartamento [c/a]" << endl;
				cin >> seguro;
				if (seguro == 'c') {
                    DtDireccion* dire = new DtDireccion(numero, calle, ady);
					DtCliente *clientepepe = interfazCliente->agregarCliente(telef, nombre, dire);
					cout << clientepepe << endl;
					delete clientepepe;
				}
				else if (seguro == 'a') {
					cin.ignore();
					cout << "Ingrese nombre del edificio" << endl;
					getline(cin, ed);
					cout << "Ingrese el numero de apartamento" << endl;
					getline(cin, eddy);
                    DtApartamento* apartamento = new DtApartamento(ed, eddy, calle, ady, numero);
					DtCliente *clientepepe = interfazCliente->agregarCliente(telef, nombre, apartamento);
					cout << clientepepe << endl;
					delete clientepepe;

				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
				cout << "confirmar[y/n]" << endl;
				cin >> seguro;
				cin.ignore();//ignore el ENTER precinado en el menu
				if (seguro == 'y') {
					interfazCliente->aceptarCliente();
				}
				else if (seguro == 'n') {
					interfazCliente->cancelarCliente();
					cout << "El cliente no fue ingresado al sistema, Usted cancelo el alta de cliente" << endl;
					system("pause");
					throw('x');
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
			}if (interfazProducto->masDeUnProducto()) {
				set<DtComida*> dtc = interfazProducto->listaDeComidaDisponible();
				set<DtComida*>::iterator iter;
				for (iter = dtc.begin(); iter != dtc.end(); iter++) {
					cout << (*iter) << endl;
				}
				dtc.clear();
				bool nosalir = true;
				string cod;
				int cant;
				while (nosalir) { //CORREGIR LOS CIN.IGNORE() QUE ESTAN TODOS MAL
					cout << "Ingrese codigo" << endl;
					getline(cin, cod);
					if (!interfazProducto->existeComida(cod)) {
						throw(13);
					}
					cout << "ingrese la cantidad" << endl;
					cin >> cant;
					cin.ignore();//ignore el ENTER precinado en el menu
					interfazVenta->seleccionarComida2(cod, cant);
					cout << "Desea seguir agregando comidas [y/n]" << endl;
					cin >> seguro;
					cin.ignore();//ignore el ENTER precinado en el menu
					if (seguro == 'n') {
						nosalir = false;
					}
					else if (seguro != 'y') {
						cout << "Por favor ingrese los datos pedidos" << endl;
						interfazVenta->cancelarVentaADomicilio();
						throw('x');
					}
				}
				cout << "Deseas solicitar un repartidor[y/n]" << endl;
				
				cin >> seguro;
				cin.ignore();//ignore el ENTER precinado en el menu
				bool retiraEnLocal = true;
				if (seguro == 'y') {
					retiraEnLocal = false;
					set<DtDelivery*> dtrepartidores = interfazEmpleado->darRepartidores();
					if (dtrepartidores.empty()) {
						cout << "No hay repartidores" << endl;
						throw ('x');
					}
					set<DtDelivery*>::iterator iter;
					for (iter = dtrepartidores.begin(); iter != dtrepartidores.end(); iter++) {
						cout << (*iter) << endl;
					}
					dtrepartidores.clear();
					int repartidor;
					cout << "Elija un repartidor por su nroEmpleado" << endl;
					cin >> repartidor;
					interfazVenta->seleccionarRepartidor(repartidor);
				}
				else if (seguro != 'n') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					interfazVenta->cancelarVentaADomicilio();
					throw('x');
					
				}
				cout << "Desea confirmar [y/n]" << endl;
				cin >> seguro;
				if (seguro == 'y') {
					interfazVenta->confirmarVentaADomicilio();
					int des;
					cout << "Ingrese el descuento, en caso de no aplicar ingrese(0)" << endl;
					cin >> des;
					if (!retiraEnLocal) {
						DtFacturaDomicilio dfd = interfazVenta->facturarVentaADomicilio(des);
						cout << "" << &dfd << endl;
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
					interfazVenta->cancelarVentaADomicilio();
					throw('x');
				}
			}
			else {
				cout << "El Sistema no tiene productos disponibles en el momento" << endl;
				
				
			}
			system("pause");
		}
		else if (comando == 'f') {
			bool consultar = true;
			bool esta = true;
			string cod;
			cin.ignore();//ignore el ENTER precinado en el menu
			while (consultar) {
				system("CLS");//limpia la pantalla
				set<DtComida*> dtc = interfazProducto->listaDeComidaDisponible();
				set<DtComida*>::iterator iter;
				for (iter = dtc.begin(); iter != dtc.end(); iter++) {
					DtProducto *p = dynamic_cast<DtProducto*>(*iter);
					DtMenu *m = dynamic_cast<DtMenu*>(*iter);

					if (p) {
						cout << p << endl;
					
					}
					else {
						cout << m << endl;
					
					}
				

				}
				dtc.clear();
				cout << "Que comida desea consultar" << endl;
				getline(cin, cod);
				bool hay = interfazProducto->existeComida(cod);
				if (!hay) {
					cout << "todo bien, te liste los codigo y le erraste igual" << endl;
					throw ('x');
				}
			
				esta = interfazProducto->existeComida(cod);
				if (esta) {
					DtComida* dt = interfazProducto->ingresarCodigoParaInfo();
					
					DtMenu* menu = dynamic_cast<DtMenu*>(dt);
					DtMenuVenta* menuvt = dynamic_cast<DtMenuVenta*>(menu);
					
					DtProducto* prod = dynamic_cast<DtProducto*> (dt);
					DtProductoVenta* prodvt = dynamic_cast<DtProductoVenta*>(prod);
					
					if (menuvt == NULL && prodvt == NULL) {
						cout << "estan mal los cast" << endl;
						throw ('z');
					}
					
					else if (menuvt == NULL) {
						cout << endl;
						cout << "Estos son los daots que solicito" << endl;
						cout << prodvt << endl;
					}
					else {
						cout << endl;
						cout << "Estos son los datos que solicito y la cantidad vendida" << endl;
						cout << menuvt << endl;
					}
					delete dt;
				}
				cout << "Desea seguir consultando[y/n]" << endl;
				cin >> seguro;
				cin.ignore();//ignora ENTER
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
							cout << endl;
							DtFacturaResumen dfr = interfazVenta->resumenDelDia(d, m, a);
							cout << "" << &dfr << endl;
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
			system("pause");
		}
		else if (comando == 'h') {
			if (interfazProducto->masDeUnProducto()) {
				set<DtComida*> dtc = interfazProducto->listaDeComidaDisponible();
				set<DtComida*>::iterator iter;
				cout << endl;
				system("CLS");//limpia la pantalla
				for (iter = dtc.begin(); iter != dtc.end(); iter++) {
					cout << *iter << endl;
				}
				dtc.clear();
				cin.ignore();//ignore el ENTER precinado en el menu
				cout << "Ingrese el codigo deseado" << endl;
				string cod;
				getline(cin, cod);
				interfazProducto->ingresarCodigo(cod);
				cout << "Desea confirmar [y/n] " << endl;
				cin >> seguro;
				if (seguro == 'y') {
					if (interfazProducto->existeComida(cod)) {
						interfazProducto->confirmarBaja();
					}
					else {
						throw(11);
					}
					
				}
				else if (seguro == 'n') {
					interfazProducto->cancelarBaja();
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
			}
			else {
				cout << "El Sistema no tiene productos disponibles en el momento" << endl;
				system("pause");
			}
			
		}
		else if (comando == 'i') {
		cout << endl << endl;
		set<set<DtEstadoTerminado>> act = interfazCliente->verTodasActualizaciones();
		set<set<DtEstadoTerminado>>::iterator i;
		set<DtEstadoTerminado>::iterator j;
		for (i = act.begin(); i != act.end(); i++) {
			set<DtEstadoTerminado> pepe = (*i);
			for (j = pepe.begin(); j != pepe.end(); j++) {
				DtEstadoTerminado aux = (*j);
				cout << "" << &aux << endl;
			}
		}
		system("pause");
		}// caso i

		else if (comando == 'x') {
		salir = 21; //2121212121 twenty one tueni wuan
		}
		
	}//while


}//menuadmin

void menuPosta() {
	bool datosCargados = false;

	int salir = 0;
	while (!salir) {
		char comando;
		system("CLS");//limpia la pantalla
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
		try {

			if (comando == '1') {
				menu_admin();
			}
			else if (comando == '2') {
				if (mesasAsignadas) {
					menuMozo();
				}
				else {
					cout << "Tiene que asignar mesas a mozo primer" << endl;
					system("pause");
				}
				
			}
			else if (comando == '3') {
				menuRepartidor();
			}
			else if (comando == '4') {
				menuCliente();
			}
			else if (comando == '5') {
				if (datosCargados == false) {
					cargarDatos();
					datosCargados = true;
				}
				else {
					cout << "Los datos ya fueron cargado" << endl;
					system("pause");
				}
				
			}
			else if (comando == '6') {
				salir = 21;
			}
		}catch (char pepe) {
			cout << "exploto" << endl;
			system("pause");

		}catch (int a) {
			switch (a) {
			case 1: cout << "Existe una venta no facturada que tiene el producto que quieres eliminar" << endl;
				break;
			case 2: cout << "No se puede ingresar un menu dentro de otro menu" << endl;
				break;
			case 3: cout << "El codigo no pertenece a un producto" << endl;
				break;
			case 4: cout << "El numero de empelado corresponde a un Delivery y no a un Mozo" << endl;
				break;
			case 5: cout << "El numero de empleado correspone a un Mozo y no a un Delivery" << endl;
				break;
			case 6: cout << "La cantidad de mozos en menor a la cantidad de mesas" << endl;
				break;
			case 7: cout << "No hay mozos" << endl;
				break;
			case 8: cout << "Usted ingreso una mesa que ya contiene una venta asociada a ella, el caso de uso se a cancelado" << endl;
				break;
			case 9: cout << "La venta no existe" << endl;
				break;
			case 10: cout << "Ya existe un cliente con ese numero de telefono" << endl;
				break;
			case 11: cout << "No existe la comida con ese codigo" << endl;
				break;
			case 12: cout << "La mesa selecciona no le pertence al mozo o esta ocupada" << endl;
				break;
			case 13: cout << "El producto no existe" << endl;
				break;
			}
			system("pause");
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
		rep->siguienteEstado(num);						//No tiene por qué ser en venta, hay que verlo    //Hay que tirar error aca
		cout << "El estado ha sido actualizado" << endl;
	}
	else if (x == 'c') {
		rep->cancelarPedido(num);					//Hay que tirar error aca
		cout << "El pedido ha sido cancelado" << endl;
	}
	system("pause");
}
//Hay dos funciones de ver actualizaciones (en venta y en cliente)
void menuCliente() {
	string tel;
	system("CLS");//limpia la pantalla
	

	cout << "Ingrese el numero de telefono" << endl;
	cin.ignore();//ignore el ENTER precinado en el menu
	getline(cin, tel);
	Fabrica* factory = Fabrica::getInstance();
	ICliente* cliente = factory->getICliente();
	if (cliente->existeCliente(tel)) {
		set<DtEstadoTerminado> printer = cliente->verActualizacion(tel);			//Esto tira error?
		set<DtEstadoTerminado>::iterator iter;
		for (iter = printer.begin(); iter != printer.end(); iter++) {
			DtEstadoTerminado temp = *iter;
			cout << &temp << endl;
		}
 	}
	system("pause");
	
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
			if (!cin) {
				cout << "Tiene que ser un entero" << endl;
				throw('x');
			}
			cin.ignore();
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			set<int> printer = ventas->mesasAsignadas(num);
			set<int>::iterator iter;
			cout << endl;
			cout << "Estas son las mesas disponibles" << endl;

			for (iter = printer.begin(); iter != printer.end(); iter++) {
				int i = *iter;
				cout << i << endl;
			}

			
			bool quiereAgregar = true;
			while (quiereAgregar) {
				cout << "Ingrese un numero de mesa"  << endl;
				cin >> num;
				cin.ignore();
				
				
				//verificamos mesa
				set<int>::iterator iter;
				bool perteneceMesa = false;
				for (iter = printer.begin(); iter != printer.end(); iter++) {
					if ((*iter) == num) {
						perteneceMesa = true;
					}
				}
				if (perteneceMesa){
					ventas->agregarMesaAVenta(num);
				}
				else {
					throw(12);
				}

				
				cout << "Quiere seguir agregando? [y/n]" << endl;
				char cont;
				cin >> cont;
				cin.ignore();
				if (cont == 'y') {
					quiereAgregar = true;
				}
				else if (cont == 'n') {
					quiereAgregar = false;
				}
				else {
					cout << "Por favor ingrese los datos pedidos" << endl;
					ventas->descartarVentasEnMesa();
					throw ('x');
				}
			}
			cout << endl;
			cout << "Estas son las mesas seleccionada" << endl;
			printer = ventas->mostrarMesasSeleccionadas();
			for (iter = printer.begin(); iter != printer.end(); iter++) {
				cout << (*iter) << endl;
			}
			cout << "Desea confirmar? [y/n]" << endl;
			char cont;
			cin >> cont;
			cin.ignore();
			if (cont == 'y') {
				ventas->confirmarVentaEnMesas();
			}
			else if (cont == 'n') {
				ventas->descartarVentasEnMesa();
			}
			else {
				cout << "Por favor ingrese los datos pedidos" << endl;
				ventas->descartarVentasEnMesa();
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
			cin.ignore();
			ventas->ingresarNroMesa(nromesa);
			set<DtComida*> dtc = productos->listaDeComidaDisponible();
			set<DtComida*>::iterator iter;
			for (iter = dtc.begin(); iter != dtc.end(); iter++) {
				cout << (*iter) << endl; 
			}
			bool seguir = true;
			string cod;
			int cant;
			char seguro;
			while (seguir) {
				cout << "Ingrese el codigo de la comida a agregar a la venta" << endl;
				getline(cin, cod);
				cout << "Ingrese la cantidad" << endl;
				cin >> cant;
				ventas->seleccionarComida(cod, cant);
				cout << "Desea confirmar[y/n]" << endl;
				cin >> seguro;
				cin.ignore();
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
					ventas->descartarAgregado();
					throw ('x');
				}
				cout << "Desea seguir agregando[y/n]" << endl;
				cin >> seguro;
				cin.ignore();
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
			cout << "Ingrese el numero de mesa" << endl;
			int nro;
			cin >> nro;
			cin.ignore();
			cout << endl << endl;
			set <DtComida> comidas = ventas->productosEnVentaEnMesa(nro);
			set<DtComida>::iterator iter;
			DtComida p;
			if (comidas.empty()) {
				cout << "No existen comidas a quitar" << endl;
				throw('x');
			}
			for (iter = comidas.begin(); iter != comidas.end(); iter++) {
				p = (*iter);
				cout << &p << endl;
			}
			bool seguirQuitando = true;
			string cod;
			char seguro;
			int cant;
			while (seguirQuitando) {
				cout << "Ingrese el codigo de la comida a quitar" << endl;
				getline(cin, cod);
				cout << "ingrese la cantidad a quitar" << endl;
				cin >> cant;
				cin.ignore();
				ventas->seleccionarComida(cod, cant);
				cout << "Desea confirmar [y/n]" << endl;
				cin >> seguro;
				cin.ignore();
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
					ventas->descartarEliminacion();
					throw ('x');
				}
				cout << "Desea seguir quitando [y/n]" << endl;
				cin >> seguro;
				if (seguro == 'n') {
					seguirQuitando = false;
				}
				else if (seguro != 'y') {
					cout << "Por favor ingrese los datos pedidos" << endl;
					throw('x');
				}
				cin.ignore();
			}
			ventas->liberarnroMesa();
		}
		else if (comando == 'd') {
			Fabrica* factory = Fabrica::getInstance();
			IVenta* ventas = factory->getIVenta();
			int nromesa;
			int des;
			cout << "Ingrese el numero de mesa" << endl;
			cin >> nromesa;
			cin.ignore();
			set <DtComida> comidas = ventas->productosEnVentaEnMesa(nromesa);
			if (comidas.empty()) {
				cout << "no puede facturar una venta sin productos" << endl;
				throw('x');
			}
			cout << "ingrese el descuento, en caso de no aplicar descuento ingrese (0)" << endl;
			cin >> des;
			cin.ignore();
			DtFactura *res = ventas->generarFactura(nromesa, des);
			cout << "" << res << endl;
		}
		else if (comando == 'e') {
			salir = 21;
		}// 2212221122212121122 twenty one tuenti wuane

	}
} //menumozo

void cargarDatos() {

	Fabrica *fab = Fabrica::getInstance();
	IEmpleado * interfazEmpleado = fab->getIEmpleado();
	IProducto *interfazProducto = fab->getIProducto();
	interfazProducto->agregarDatosPredef();
	interfazEmpleado->agregarMozo("Juan Pedro");
	interfazEmpleado->confirmarEmpleado();//agregado
	interfazEmpleado->agregarMozo("Jonny");
	interfazEmpleado->confirmarEmpleado();//agregado
	interfazEmpleado->agregarMozo("Jose");
	interfazEmpleado->confirmarEmpleado();//agregado
	interfazEmpleado->agregarDelivery("Tito");
	interfazEmpleado->elegirVehiculo(BICI);
	interfazEmpleado->confirmarEmpleado();//agregado
	interfazEmpleado->agregarDelivery("Raul");
	interfazEmpleado->elegirVehiculo(MOTO);
	interfazEmpleado->confirmarEmpleado();//agregado
	interfazEmpleado->agregarDelivery("Tiki Gelana");
	interfazEmpleado->elegirVehiculo(PIE);
	interfazEmpleado->confirmarEmpleado();//agregado

	//Cliente

	ICliente *interfazCliente = fab->getICliente();
	DtApartamento* edificio = new DtApartamento("Mar Austral", "701", "18 de Julio", "None", "2033");
	DtDireccion* casita = edificio;
	interfazCliente->agregarCliente("098217523", "Vladimir", casita);
	interfazCliente->aceptarCliente();//agregado
	delete edificio;



	casita = new DtDireccion("500", "Cabildo", "None");
	interfazCliente->agregarCliente("091651249", "Martin", casita);
	interfazCliente->aceptarCliente();//agregado
	delete casita;

	edificio = new DtApartamento("Atlantis", "302", "Avenida Brasil", "None", "842");
	casita = edificio;
	interfazCliente->agregarCliente("097321590", "Ronaldo", casita);
	interfazCliente->aceptarCliente();//agregado
	delete edificio;


	//Ventas a domicilio



	IVenta* interfazVenta = fab->getIVenta();
	string telef = "091651249";
	interfazVenta->iniciarVentaADomicilio(telef);
	interfazVenta->seleccionarComida2("7", 5);
	interfazVenta->seleccionarRepartidor(4);
	DtHora horita = DtHora(13, 21);
	interfazVenta->confirmarVentaADomicilio(horita);
	DtFacturaDomicilio dfd = interfazVenta->facturarVentaADomicilio(0);
	horita = DtHora(27,21);
	interfazVenta->siguienteEstado(4, horita);


	interfazVenta->iniciarVentaADomicilio(telef);
	interfazVenta->seleccionarComida2("2", 2);
	interfazVenta->seleccionarRepartidor(5);
	horita = DtHora(15, 16);
	interfazVenta->confirmarVentaADomicilio(horita);
	dfd = interfazVenta->facturarVentaADomicilio(0);
	horita = DtHora(02, 15);
	interfazVenta->siguienteEstado(5,horita);
	horita = DtHora(37, 16);
	interfazVenta->siguienteEstado(5,horita);



	telef = "098217523";
	interfazVenta->iniciarVentaADomicilio(telef);
	interfazVenta->seleccionarComida2("6", 1);
	interfazVenta->seleccionarRepartidor(4);
	horita = DtHora(14, 21);
	interfazVenta->confirmarVentaADomicilio(horita);
	dfd = interfazVenta->facturarVentaADomicilio(0);
	horita = DtHora(27, 21);
	interfazVenta->siguienteEstado(6, horita);
	interfazVenta->iniciliazarMesas();
	cout << "Se han cargado todos los datos predeterminados" << endl;
	system("pause");

}