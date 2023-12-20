// Foi realizada uma pesquisa de algumas características de pessoas. Para cada pessoa devem ser definidas
// as seguintes informações em C++ para um objeto do tipo Pessoa (definido por uma classe) com os
// seguintes atributos (private) (1 ponto):
// 		nome (string) e altura (double)
// 		e com os seguintes métodos
// (public) (10 pontos): 02 construtores (um sem parâmetro com inicialização padrão; o outro com
// parâmetros para todos os atributos), get/set para cada atributo, método exibe que mostra na saída
// padrão as informações atuais dos atributos formatadas.

// Implemente também em C++ os seguintes módulos para manipulação desse objeto:
// (4 pontos) um procedimento que recebe o objeto e o nome do arquivo de entrada, preenchendo
// o objeto a partir dos dados lidos deste arquivo;

// (2 pontos) uma função que recebe o objeto e retorna true, caso a pessoa possua mais de 1,60m
// e, false, caso contrário.

// No programa principal (4 pontos), declare um objeto do tipo Pessoa, leia o nome do arquivo de entrada
// da informação e o nome do arquivo de saída, acione o procedimento e a função, gravando no arquivo
// de saída uma das mensagens conforme o resultado da função
// .

#include <iostream>

using namespace std;

// clear && g++ exercicio.cc && ./a.out

class Pessoa {
private:
	string nome;
	double altura;
public:
	Pessoa() {
		nome = "";
		altura = 0.0;
	}

	Pessoa(string nome, double altura) {
		this->nome = nome;
		this->altura = altura;
	}

	void setNome(string nome) { this->nome = nome; }
	string getNome() { return nome; }

	void setAltura(double altura) { this->altura = altura; }
	double getAltura() { return altura; }

	void exibe() {
		cout << "Nome: " << nome << endl;
		// cout << "Altura: " << altura << endl;
		printf("Altura: %.2lf\n", altura);
	}

	void exibe(FILE* arquivo) {
		fprintf(arquivo, "Nome: %s\n", nome.c_str());
		fprintf(arquivo, "Altura: %.2lf\n", altura);
	}
};

void ImportarDoArquivo(Pessoa* pessoa, FILE* arquivo) {

	char nome[80];
	fscanf(arquivo, "%[^;] %*c", nome);
	double altura;
	fscanf(arquivo, "%lf", &altura);

	(*pessoa).setNome(nome);
	pessoa->setAltura(altura);
}

// #define foo(x) (x.getAltura() > 1.6)

bool testaAltura(Pessoa pessoa) {
	return pessoa.getAltura() < 1.6;
}

string getString(string msg = "Digite uma string: ") {
	cout << msg;
	string aux;
	cin >> aux;
	return aux;
}

int main() {

	Pessoa fulano;

	string nomeArquivoEntrada = getString("Digite o nome do arquivo de entrada: ");
	string nomeArquivoSaida = getString("Digite o nome do arquivo de saída: ");

	nomeArquivoEntrada += ".txt";
	nomeArquivoSaida += ".txt";

	FILE* arquivoEntrada = fopen(nomeArquivoEntrada.c_str(), "r");
	FILE* arquivoSaida = fopen(nomeArquivoSaida.c_str(), "w");

	ImportarDoArquivo(&fulano, arquivoEntrada);

	fulano.exibe();
	fulano.exibe(arquivoSaida);

	if (testaAltura(fulano)) {
		cout << "Altura maior que 1.60" << endl;
		fprintf(arquivoSaida, "Altura maior que 1.60m");
	} else {
		cout << "Altura menor que 1.60" << endl;
		fprintf(arquivoSaida, "Altura menor ou igual a 1.60m");
	}

	// cout << foo(fulano) ? "Altura maior que 1.60" : "Altura menor que 1.60"

	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	return 0;
}