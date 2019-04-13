#include "../Header/A.h"
#include "../Header/B.h"
#include "../Header/C.h"
#include <iostream>
#include <exception>
#include <stdio.h>




using namespace std;


int main(){
    
    bool salir = false;             
    while(!salir){
        int n1, n2, n3;
    cout << "Ingresar valores numericos seguido de un Enter:" << endl;
    
    cin >> n1;
    if(!cin){
		while (!cin) {
			cout << "Ingrese un numero, reintente" << endl;
			cin.clear();
  			std::cin.ignore(256,'\n');   
			cin >> n1;
	  }
    }
    
    cin >> n2;
    if(!cin){
		while (!cin) {
			cout << "Ingrese un numero, reintente" << endl;
			cin.clear();
			std::cin.ignore(256,'\n');
			cin >> n2;
		}
    }
    cin >> n3;
    if(!cin){
		while (!cin) {
			cout << "Ingrese un numero, reintente" << endl;
			cin.clear();
			std::cin.ignore(256,'\n');
			cin >> n3;
		}
    } 
    
    A *obja = new A(n1);
    B *objb = new B(n2);
    C *objc = new C(n3);
    obja->imprimira();
    objb->imprimirb();
    objc->imprimirc();

    delete obja;
    delete objb;
    delete objc;
    cout << "¿Salir[y/n]?";
    char pepe;
    cin >> pepe;
    
    if(pepe == 'y')
        salir = true;
    }
    

    return 0;
}
