#include <iostream>

using namespace std;

// clear && g++ IntroHeranca.cc && ./a.out

// A herança pública herda os atributos / metodos
// da classe pai com a mesma configuração de encapsulamento.

#define herda public

class Animal {
private:
	int idade;
	string nome;
public:

	Animal() {}

	Animal(int idade, string nome) {
		cout << "Construtor: Animal" << endl;
		this->idade = idade;
		this->nome = nome;
	}

	void Falar() {
		cout << "Sou um animal." << endl;
	}

	void setNome(string nome) { this->nome = nome; }
	void setIdade(int idade) { this->idade = idade; }
	string getNome() { return nome; }
	int getIdade() { return idade; }
};

class Cachorro : herda Animal {
public:

	Cachorro(int idade, string nome) : Animal(idade, nome) {
		// cout << "Construtor: Cachorro" << endl;
	}

	void Falar() { // Overwrite - Sobrecrita
		cout << "Sou um cachorro." << endl;
	}

	void Printar() {
		cout << "Nome: " << getNome() << endl;
		cout << "Idade: " << getIdade() << endl;
	}
};

class Gato : herda Animal {
public:
	void Falar() {
		cout << "Sou um gato." << endl;
	}
};

int main() {

	Cachorro dog(5, "Cachorro");
	dog.Falar();

	return 0;
}