// #include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
// #include <sstream>
// #include <vector>

using namespace std;

class Personagem {
private:
	string nome;
	int altura;
	double peso;
	string corDoCabelo;
	string corDaPele;
	string corDosOlhos;
	string anoNascimento;
	string genero;
	string homeworld;

public:
	Personagem(string nome, int altura, double peso, string corDoCabelo, string corDaPele, string corDosOlhos,
		string anoNascimento, string genero, string homeworld) {
		setNome(nome);
		setAltura(altura);
		setPeso(peso);
		setCorDoCabelo(corDoCabelo);
		setCorDaPele(corDaPele);
		setCorDosOlhos(corDosOlhos);
		setAnoNascimento(anoNascimento);
		setGenero(genero);
		setHomeworld(homeworld);
	}

	Personagem() {
		setNome("");
		setAltura(0);
		setPeso(0.0);
		setCorDoCabelo("");
		setCorDaPele("");
		setCorDosOlhos("");
		setAnoNascimento("");
		setGenero("");
		setHomeworld("");
	}

	// Setter e Getter para o atributo nome
	void setNome(string nome) {
		this->nome = nome;
	}
	string getNome() {
		return nome;
	}

	// Setter e Getter para o atributo altura
	void setAltura(int altura) {
		this->altura = altura;
	}
	int getAltura() {
		return altura;
	}

	// Setter e Getter para o atributo peso
	void setPeso(double peso) {
		this->peso = peso;
	}
	double getPeso() {
		return peso;
	}

	// Setter e Getter para o atributo corDoCabelo
	void setCorDoCabelo(string corDoCabelo) {
		this->corDoCabelo = corDoCabelo;
	}
	string getCorDoCabelo() {
		return corDoCabelo;
	}

	// Setter e Getter para o atributo corDaPele
	void setCorDaPele(string corDaPele) {
		this->corDaPele = corDaPele;
	}
	string getCorDaPele() {
		return corDaPele;
	}

	// Setter e Getter para o atributo corDosOlhos
	void setCorDosOlhos(string corDosOlhos) {
		this->corDosOlhos = corDosOlhos;
	}
	string getCorDosOlhos() {
		return corDosOlhos;
	}

	// Setter e Getter para o atributo anoNascimento
	void setAnoNascimento(string anoNascimento) {
		this->anoNascimento = anoNascimento;
	}
	string getAnoNascimento() {
		return anoNascimento;
	}

	// Setter e Getter para o atributo genero
	void setGenero(string genero) {
		this->genero = genero;
	}
	string getGenero() {
		return genero;
	}

	// Setter e Getter para o atributo homeworld
	void setHomeworld(string homeworld) {
		this->homeworld = homeworld;
	}
	string getHomeworld() {
		return homeworld;
	}

	void Ler(string filePath) {

		ifstream file(filePath);
		string jsonString;
		getline(file, jsonString);
		jsonString = regex_replace(jsonString, regex("é"), "\u00e9");
		file.close();

		// cout << jsonString << endl;

		// Separando keys e values e atribuindo a suas variaveis
		string pairs = jsonString.substr(1, jsonString.length() - 1);
		int pos = 0;
		while ((pos = pairs.find(", '")) != string::npos) {
			string pair = pairs.substr(0, pos);
			pairs.erase(0, pos + 1);

			int splitPos = pair.find(":");
			string key = pair.substr(1, splitPos - 2);
			string value = pair.substr(splitPos + 2, pair.length() - splitPos - 3);

			if (key == "name") {
				this->nome = value.substr(1);
			} else if (key == "'height") {
				this->altura = stoi(value.substr(1));
			} else if (key == "'mass") {
				this->peso = stod(value.substr(1));
			} else if (key == "'hair_color") {
				this->corDoCabelo = value.substr(1);
			} else if (key == "'skin_color") {
				this->corDaPele = value.substr(1);
			} else if (key == "'eye_color") {
				this->corDosOlhos = value.substr(1);
			} else if (key == "'birth_year") {
				this->anoNascimento = value.substr(1);
			} else if (key == "'gender") {
				this->genero = value.substr(1);
			} else if (key == "'homeworld") {
				this->homeworld = value.substr(1);
			} else {
				break;
			}
		}
	}

	void Imprimir() {
		cout << " ## " << this->nome;
		cout << " ## " << this->altura;
		cout << " ## " << this->peso;
		cout << " ## " << this->corDoCabelo;
		cout << " ## " << this->corDaPele;
		cout << " ## " << this->corDosOlhos;
		cout << " ## " << this->anoNascimento;
		cout << " ## " << this->genero;
		cout << " ## " << this->homeworld;
		cout << " ## " << endl;
	}

	Personagem clone() {
		Personagem cloned;

		cloned.nome = this->nome;
		cloned.altura = this->altura;
		cloned.peso = this->peso;
		cloned.corDoCabelo = this->corDoCabelo;
		cloned.corDaPele = this->corDaPele;
		cloned.corDosOlhos = this->corDosOlhos;
		cloned.anoNascimento = this->anoNascimento;
		cloned.genero = this->genero;
		cloned.homeworld = this->homeworld;

		return cloned;
	}
};

int main() {
	string input;

	cin >> input;

	while (input.compare("FIM")) {
		Personagem personagem;

		personagem.Ler(input);
		personagem.Imprimir();

		cin >> input;
		input = regex_replace(input, regex("é"), "\u00e9");
	}

	return 0;
}