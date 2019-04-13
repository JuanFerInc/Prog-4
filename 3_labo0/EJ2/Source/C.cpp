#include "../Header/C.h"
#include <iostream>
 
using namespace std;

C::C(int arg){
    this->c = arg;
}


void C::imprimirc(){
    cout << "Clase C, valor:" << this->c << endl;
}
