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
	virtual void printmesomthing() {
		cout << "not pure" << endl;
	}
};


class B:public algo {
private :
	string nombre;
public:
	B(string n, int todo):algo(todo) {
		this->nombre = n;
	}
	string getNombre() {
		return this->nombre;
	}
	void printmesomthing() {
		cout << "yay "<< this->getTodo() << endl;
	}
};

algo *test(int total) {
	
	static B a("Juan", total);
	a.setTodo(total);
	algo*res = &a;
	//cout << total << endl;
	//cout << a.getTodo() <<endl;
	return res;
}

int main() {
	
	algo *uno = test(100);
	
	algo *dos;

	for (int i = 0 ; i < 10000000; i++) {
		 dos = test(i);
	}
	


	uno->printmesomthing();
	dos->printmesomthing();


	system("pause");






	return 0;
}