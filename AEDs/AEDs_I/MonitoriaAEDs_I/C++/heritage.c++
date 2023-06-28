#include <biblioteca_cpp.h>

class Animal {
	int	   idade;
	string habitatNatural, nome;

  public:
	void setIdade(int idade) {
		this->idade = idade;
	}
	void setHabitatNatural(string habitatNatural) {
		this->habitatNatural = habitatNatural;
	}
	void setNome(string nome) {
		this->nome = nome;
	}
};

class Vaca: extends Animal {
	int qtdLeite;

  public:
	Vaca() {
		cout << "Construtor vaca" << endl;
		qtdLeite = 100;
	}
	void DarLeite(int qtdLeiteTirado) {
		qtdLeite -= qtdLeiteTirado;
	}

	int getLeite() {
		return qtdLeite;
	}
};

int main() {

	Vaca vaca;
	vaca.DarLeite(25);
	cout << vaca.getLeite() << endl;

	vaca.setNome("Vaca1");

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}