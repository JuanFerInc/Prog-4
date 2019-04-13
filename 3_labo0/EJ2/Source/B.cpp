#include "../Header/B.h"
#include <iostream>
 
 using namespace std;
 
B::B(int arg){
    this->b = arg;
}


void B::imprimirb(){
    cout << "Clase B, valor:" << this->b << endl;
}
