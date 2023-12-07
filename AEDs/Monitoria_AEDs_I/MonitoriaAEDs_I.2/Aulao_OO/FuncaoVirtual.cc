#include <iostream>

// clear && g++ FuncaoVirtual.cc && ./a.out

using namespace std;

#define herda public

class Animal {
public:
	void Falar() {
		cout << "Animal: Falando" << endl;
	}
};

class Cachorro : herda Animal {
	public:
	void Falar() {
		cout << "Cachorro: Falando" << endl;
	}
};

class Gato : herda Animal {
	public:
	void Falar() {
		cout << "Gato: Falando" << endl;
	}
};

int main() {

	// Animal* array[2];

	// array[0] = new Cachorro();
	// array[1] = new Gato();

	Animal array[2];

	Cachorro dog;
	Gato cat;

	array[0] = dog;
	array[1] = cat;

	array[0].Falar();

	return 0;
}