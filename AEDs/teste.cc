#include <iostream>

using namespace std;

class Teste {
	public:
	Teste() {
		cout << "Construtor chamado" << endl;
	}
	Teste(int teste) {
		cout << "Construtor chamado: " << teste << endl;
	}
};

int main() {

	Teste t1;
	Teste t2(2);

	return 0;
}