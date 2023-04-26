#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int totalDonators = 0;

class Doador {
	string _nome;
	string _telefone;
	string _tipoSanguineo;
	//-----------------------
	int _idade, _peso, _doacoesUltimoAno, _intervEntreDoacoes;
	bool _hasDonated;
	char _sexo;
	bool _CadastroSucedido;

public:
	// Doador(string nome, string telefone, string tipoSanguineo, int idade, bool hasDonated, int peso, int doacoesUltimoAno, char sexo, int intervEntreDoacoes) {
	// 	_CadastroSucedido = false;
	// 	if (idade < 16 || idade > 69) {
	// 		cout << "Doador não atende os requisitos de idade." << endl;
	// 	} else if (idade >= 60) {
	// 		if (!hasDonated) {
	// 			cout << "Doadores acima dos 60 anos devem ter doado anteriormente." << endl;
	// 		}
	// 	} else if (peso <= 50) {
	// 		cout << "Doador não atende os requisitos de peso." << endl;
	// 	} else if (doacoesUltimoAno > 3 && doacoesUltimoAno < 4) {
	// 		if (sexo == 'F' || sexo == 'f') {
	// 			cout << "Doador não atende os requisitos de doações anuais." << endl;
	// 		} else {
	// 			if (doacoesUltimoAno > 4) {
	// 				cout << "Doador não atende os requisitos de doações anuais." << endl;
	// 			}
	// 		}
	// 	} else if (intervEntreDoacoes < 3) {
	// 		if (sexo == 'F' || sexo == 'f') {
	// 			cout << "Doador não atende os requisitos de doações anuais." << endl;
	// 		} else {
	// 			if (intervEntreDoacoes < 2) {
	// 				cout << "Doador não atende os requisitos de doações anuais." << endl;
	// 			}
	// 		}
	// 	} else {
	// 		cout << "Doador cadastrado com sucesso!\n\n";
	// 		_sexo = sexo;
	// 		_nome = nome;
	// 		_telefone = telefone;
	// 		_tipoSanguineo = tipoSanguineo;
	// 		_idade = idade;
	// 		_peso = peso;
	// 		_doacoesUltimoAno = doacoesUltimoAno;
	// 		_intervEntreDoacoes = intervEntreDoacoes;
	// 		_hasDonated = hasDonated;
	// 		_CadastroSucedido = true;
	// 	}
	// }

	Doador(string nome, string telefone, string tipoSanguineo) {
		cout << "Doador cadastrado com sucesso!\n\n";
		_sexo = '\0';
		_nome = nome;
		_telefone = telefone;
		_tipoSanguineo = tipoSanguineo;
		_idade = 0;
		_peso = 0;
		_doacoesUltimoAno = 0;
		_intervEntreDoacoes = 0;
		_hasDonated = NULL;
		_CadastroSucedido = true;
	}

	bool _getCadastroSucedido() {
		return _CadastroSucedido;
	}

	string _getNome() {
		return _nome;
	}
	string _getTelefone() {
		return _telefone;
	}
	string _getTipoSanguineo() {
		return _tipoSanguineo;
	}
};

void SalvarDoador(Doador donator) {
	if (donator._getCadastroSucedido()) {
		fstream doadores;
		// doadores.open("doadores.txt", ios::in);
		// doadores >> totalDonators;
		// doadores.close();
		doadores.open("doadores.txt", ios::app);
		totalDonators++;
		doadores << totalDonators << " { " << donator._getNome() << " - ";
		doadores << donator._getTelefone() << " - ";
		doadores << donator._getTipoSanguineo() << " }" << endl;
		// doadores << totalDonators << endl;
		doadores.close();
	}
}

void cadastrarNovoDoador() {
	string nome, telefone, tipoSanguineo;
	char aux, sexo;
	int idade, peso, doacoesUltimoAno, intervEntreDoacoes;
	bool hasDonated;

	// cout << "Sexo do doador [M/F]: ";
	// cin >> sexo;

	cout << "Nome do doador: ";
	cin >> nome;

	cout << "Telefone do doador: ";
	cin >> telefone;

	cout << "Tipo sanguineo do doador: ";
	cin >> tipoSanguineo;

	{
		// cout << "Idade do doador: ";
		// cin >> idade;

		// cout << "Já doou antes? [S/N]: ";
		// cin >> aux;
		// hasDonated = (aux == 'S' || aux == 's') ? true : false;

		// cout << "Peso do doador: ";
		// cin >> peso;

		// cout << "Quantas vezes o doador doou nos últimos 12 meses: ";
		// cin >> doacoesUltimoAno;

		// cout << "Intervalo entre a última doação: ";
		// cin >> doacoesUltimoAno;

		// Doador doador(nome, telefone, tipoSanguineo, idade, hasDonated, peso, doacoesUltimoAno, sexo, doacoesUltimoAno);
	}

	Doador doador(nome, telefone, tipoSanguineo);

	SalvarDoador(doador);
}

int main() {
	SetConsoleOutputCP(65001);

	char resposta;

	do {
		cout << "Cadastrar novo doador? [S/N]: ";
		cin >> resposta;
		if (resposta == 'S' || resposta == 's') cadastrarNovoDoador();
	} while (resposta != 'N' && resposta != 'n');

	cout << "\n********* | FIM DO PROGRAMA | *********\n\n";
	return 0;
}