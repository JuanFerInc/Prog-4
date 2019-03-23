#include "../Header/A.h"
#include "../Header/B.h"
#include "../Header/C.h"
#include <iostream>
#include <exception>
#include <stdio.h>




using namespace std;


int main(){
    try{
    bool salir = false;             
    while(!salir){
        int n1, n2, n3;
    cout << "Ingresar valores numericos seguido de un Enter:" << endl;
    
    cin >> n1;
    if(!cin){
        //cout << "Ingrese un numero, reintente " << endl;
        throw invalid_argument("Tipo de entrada incorrecta");
    }
    
    cin >> n2;
    if(!cin){
       // cout << "Ingrese un numero, reintente" << endl;
        throw invalid_argument("Tipo de entrada incorrecta");
    }
    cin >> n3;
    if(!cin){
       // cout << "Ingrese un numero, reintente" << endl;
        throw invalid_argument("Tipo de entrada incorrecta");
    } 
    
    A *obja = new A(n1);
    B *objb = new B(n2);
    C *objc = new C(n3);
    obja->imprimira();
    objb->imprimirb();
    objc->imprimirc();
    cout << "¿Salir[y/n]?";
    char pepe;
    cin >> pepe;
    
    if(pepe != 'n')
        salir = true;
    }
    }catch(const exception& invalid_argument){
        cout << "Reintente, porfavor ingrese un numero" << endl;
    }
    return 0;
}
