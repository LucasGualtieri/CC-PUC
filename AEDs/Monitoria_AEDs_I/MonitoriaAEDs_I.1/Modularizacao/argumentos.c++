#include <biblioteca_cpp.h>

class Pessoa {
  public:
	string nome;
	int	   idade, peso, altura;

	Pessoa() {
		cout << "Estou sendo criado!" << endl;
		nome   = "";
		idade  = 0;
		peso   = 0;
		altura = 0;
	}

	Pessoa(string nome, int idade, int peso, int altura) {
		this->nome	 = nome;
		this->idade	 = idade;
		this->peso	 = peso;
		this->altura = altura;
	}

	void fala(string msg) {
		cout << msg << endl;
	}
};

int main() {

	Pessoa p1("Fulano", 21, 80, 170), p2;

	// cout << p1.nome << endl;
	// cout << p1.idade << endl;
	// cout << p1.peso << endl;
	// cout << p1.altura << endl;

	// p1.fala("Oi!");

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}