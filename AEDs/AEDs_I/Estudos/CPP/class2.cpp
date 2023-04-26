#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

class Pessoa {
	string nome, cpf;
	int idade;

public:
	Pessoa() {
		cout << "Pessoa criada com sucesso!" << endl;
		nome = "Nome";
		cpf = "000.000.000-00";
		idade = 0;
	}

	// Pessoa(int idadeArg) {
	// 	nome = "Nome";
	// 	cpf = "000.000.000-00";
	// 	idade = idadeArg;
	// }

	void setNome(string nomeArg) {
		nome = nomeArg;
	}

	void setCpf(string cpfArg) {
		if (cpfArg.length() < 11 || cpfArg.length() > 14) {
			cout << "Formato errado para o campo CPF" << endl;
		} else {
			for (int i = 0, j = 0; i < cpf.length(); i++, j++) {
				if (cpfArg[i] == '.' || cpfArg[i] == '.' || cpfArg[i] == '-') i++;
				if (j == 3 || j == 7 || j == 11) j++;
				cpf[j] = cpfArg[i];
			}
		}
	}

	void setIdade(int idadeArg) {
		idade = idadeArg;
	}

	string getNome() {
		return nome;
	}
	string getCpf() {
		return cpf;
	}
	int getIdade() {
		return idade;
	}
};

float SomaFracionaria(int n, int aux = 1) {
	return (aux == n) ? 1 : pow(aux + 1, 3) / pow(10, aux) + SomaFracionaria(n, aux + 1);
}

int MultRec(int base, int expoente) {
	if (base == 0 || expoente == 0) return 0;
	return expoente > 0 ? MultRec(base, expoente - 1) + base : base;
}

void teste(string* n) {
	*n = "Lucas Gualtieri";
}

int main() {
	SetConsoleOutputCP(65001);

	Pessoa p1;

	p1.setNome("Lucas Gualtieri");
	// p1.setCpf("136.052.696-05");
	p1.setCpf("13605269605");
	p1.setIdade(20);

	cout << "Nome: " << p1.getNome() << endl;
	cout << "CPF: " << p1.getCpf() << endl;
	cout << "Idade: " << p1.getIdade() << endl;

	cout << "--------------------" << endl;

	cout << "5 * 7 = " << MultRec(5, 7) << endl;
	cout << SomaFracionaria(2) << endl;

	string n = "Lucas";

	teste(&n);

	cout << n << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}