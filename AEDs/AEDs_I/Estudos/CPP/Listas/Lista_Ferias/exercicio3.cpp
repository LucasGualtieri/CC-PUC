#include <biblioteca_cpp.h>

class Pessoa {
	string _nome;
	short _idade;
	float _alturaMetros;

public:
	Pessoa(string nome, short idade, float altura) {
		_nome = nome;
		_idade = idade;
		_alturaMetros = altura;
	}

	friend ostream& operator<<(ostream& cout, Pessoa& object) {
		cout << "Nome: " << object._nome << endl;
		cout << "Idade: " << object._idade << endl;
		cout << "Altura: " << object._alturaMetros << endl;
		return cout;
	}
};

int main() {
	SetConsoleOutputCP(65001);

	Pessoa p1("Lucas", 20, 1.87);

	cout << p1;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}