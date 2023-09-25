#include <biblioteca_cpp.h>

class Funcionario {
  private:
	// Atributos da Classe Funcionario
	string nome;
	int	   idade;
	float  salario;

  public:
	// Construtor
	Funcionario() {
		cout << "Oi, estou sendo criado!" << endl;
	}

	Funcionario(string nome, int idade, float salario) {
		cout << "Oi, estou sendo criado, mas com parâmetros!" << endl;
		this->nome	  = nome;
		this->idade	  = idade;
		this->salario = salario;
	}

	// Setter

	void setIdade(int novaIdade) {
		if (novaIdade < 18) {
			cout << "Idade inválida!" << endl;
		} else {
			idade = novaIdade;
		}
	}

	void setNome(string novoNome) {

		if (novoNome.length() <= 0 || novoNome.length() > 80) {
			cout << "Nome inválido!" << endl;
		} else {
			nome = novoNome;
		}
	}

	// Getter

	int getIdade() {
		return idade;
	}

	string getNome() {
		return nome;
	}
};

int main() {

	Funcionario f1, f2("Leozin", 18, 2'000);

	cout << f2.getNome() << endl;
	f2.setNome("Leozin da Cunha");
	cout << f2.getNome() << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}