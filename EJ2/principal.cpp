#include "../Header/A.h"
#include "../Header/B.h"
#include "../Header/C.h"
#include <iostream>




using namespace std;


int main(){
    int n1, n2, n3;
    cout << "Ingresar valores seguido de un Enter:" << endl;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    A *obja = new A(n1);
    B *objb = new B(n2);
    C *objc = new C(n3);
    obja->imprimira();
    objb->imprimirb();
    objc->imprimirc();
    return 0;
}
