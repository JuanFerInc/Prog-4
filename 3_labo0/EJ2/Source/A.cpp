#include "../Header/A.h"
#include <iostream>

using namespace std;
 
A::A(int arg){
    this->a = arg;
}

void A::imprimira(){
    cout << "Clase A, valor:" << this->a << endl;
}
