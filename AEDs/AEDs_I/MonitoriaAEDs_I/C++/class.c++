#include <iostream>
#include <string>

using namespace std;

void ReplaceAll(string& str, string change, string replace) {
	for (int i = 0; i < change.length(); i++) {
		char charToChange = change.at(i);
		for (int j = 0; j < str.length(); j++) {
			if (str.at(j) == charToChange) {
				str.erase(j, 1);
				str.insert(j, replace);
				j += replace.length();
			}
		}
	}
}

class Pessoa {
  private:
	string nome;
	int	   idade;
	float  alturaM;

  public:
	Pessoa() {
		cout << "Estou sendo criado!" << endl;
	}
	Pessoa(string novo) {
		this->nome = nome;
		cout << "Estou sendo criado! Meu nome é: " << nome << endl;
	}

	// Setters

	void setIdade(int novaIdade) {
		if (novaIdade < 0 || novaIdade > 200) {
			cout << "Idade inválida!";
		} else {
			idade = novaIdade;
		}
	}

	void setAltura(string altura) {
		ReplaceAll(altura, ",", ".");
		alturaM = stof(altura);
	}

	// Getter

	int getIdade() {
		return idade;
	}

	float getAltura() {
		return alturaM;
	}

	void imprimir() {
		cout << nome;
		cout << idade;
		cout << alturaM;
	}
};

void lerDadosPessoa(Pessoa* pessoa);

int main() {

	Pessoa Rangel;
	lerDadosPessoa(&Rangel);

	cout << Rangel.getAltura() << endl;

	// Pessoa arrayDePessoas[5];

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}

void lerDadosPessoa(Pessoa* pessoa) {

	cout << "Digite sua altura: ";
	string altura;
	cin >> altura;
	pessoa->setAltura(altura);
	// int idade;
	// cin >> idade;
	// pessoa->setIdade(idade);
}