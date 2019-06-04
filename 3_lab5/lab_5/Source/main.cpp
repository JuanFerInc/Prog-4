#include <iostream>
#include <string>
#include <set>

using namespace std;

class algo {
private:
	int todo;
public:
	algo(int todo) {
		this->todo = todo;
	}

	int getTodo() {
		return this->todo;
	}

	void setTodo(int nuevo) {
		this->todo = nuevo;
	}
	friend bool operator< (const algo &uno, const algo &dos) {
		return uno.todo < dos.todo;
	}
};
class B {
private :
	string nombre;
public:
	B(string n) {
		this->nombre = n;
	}
	string getNombre() {
		return this->nombre;
	}
	
};


int main() {
	
	
	set<algo> a;
	
	algo uno = 1;
	algo dos = 2;

	a.insert(uno);
	a.insert(dos);

	set<algo>::iterator ptr;

	algo p = 0;

	for (ptr = a.begin(); ptr != a.end(); ptr++) {
		p = *ptr;
		cout << p.getTodo() << endl;
	}
	

	system("pause");






	return 0;
}