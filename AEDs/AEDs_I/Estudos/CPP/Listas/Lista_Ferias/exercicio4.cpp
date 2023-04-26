#include "D:\Lucas\PUC\AED\workspace\C.CPP\Bibliotecas\biblioteca_cpp.h"

typedef struct Endereco Endereco;
struct Endereco {
	string cep, rua, bairro, cidade, estado;
	short numero, complemento;
};

class Pessoa {
protected:
	string _nome;
	short _idade;
	float _alturaMetros;

public:
	friend ostream& operator<<(ostream& cout, Pessoa& object) {
		cout << "Nome: " << object._nome << endl;
		cout << "Idade: " << object._idade << endl;
		cout << "Altura: " << object._alturaMetros << endl;
		return cout;
	}
};

class Employee : public Pessoa {
	double salario;
	string dataDeContratacao;

public:
	Employee(string nome, short idade, float altura) {
		_nome = nome;
		_idade = idade;
		_alturaMetros = altura;
	}
};

class Cliente : public Pessoa {
	string dataInicioFidelidade;
	Endereco endereco;

public:
	Cliente() { }

	Cliente(string nome, short idade, float altura) {
		_nome = nome;
		_idade = idade;
		_alturaMetros = altura;
	}
};

int main() {
	SetConsoleOutputCP(65001);

	Cliente cliente1;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}