#include <iostream>

// clear && g++ overload.cc && ./a.out

using namespace std;

class Animal {
	public:
	int idade;
	char nome[80];

	void operator[](char c) {
		cout << "operator[](char c): " << c << endl;
	}

	void operator[](const char* s) {
		cout << "operator[](char* s): " << s << endl;
	}

	// char operator[](int pos) {
	// 	return nome[pos];
	// }

	// char* operator[](int pos) {
	// 	return &nome[pos];
	// }

	char& operator[](int pos) {

		if (pos < 0 || pos > 80) throw string("Posição inválida");

		return nome[pos];
	}

};

int main() {

	Animal vaca;

	vaca.nome[0] = 'L';

	vaca['#'];
	vaca["Lucas"];

	cout << "vaca[0]: " << vaca[0] << endl;

	// *vaca[0] = 'E';
	// cout << "vaca[0]: " << vaca[0] << endl;

	try {
		vaca[-1] = 'E';
	} catch(string erro) {
		cout << erro << endl;
	}
	cout << "vaca[0]: " << vaca[0] << endl;

	return 0;
}