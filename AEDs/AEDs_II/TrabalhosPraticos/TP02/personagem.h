#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
using namespace std;

class Personagem {
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

	// void Ler(string filePath) throws Exception {

	// 	RandomAccessFile file = new RandomAccessFile(filePath, "r");
	// 	// string jsonstring = file.readLine().replaceAll("é", "\u00e9");
	// 	string jsonstring = file.readLine();
	// 	file.close();

	// 	// Separando keys e values e atribuindo a suas variaveis
	// 	string[] pairs = jsonstring.substring(1, jsonstring.length() - 1).split(", '");
	// 	for (string pair : pairs) {
	// 		string[] keyValue = pair.split(":");
	// 		string key = keyValue[0].replaceAll("\'", "");
	// 		string value = keyValue[1].replaceAll("\'", "").trim();

	// 		if (key.equals("name")) {
	// 			setNome(value);
	// 		} else if (key.equals("height")) {
	// 			if (value.equals("unknown")) {
	// 				setAltura(0);
	// 				continue;
	// 			}
	// 			setAltura(Integer.parseInt(value));
	// 		} else if (key.equals("mass")) {
	// 			if (value.equals("unknown")) {
	// 				setPeso(0);
	// 				continue;
	// 			}
	// 			setPeso(Double.parseDouble(value.replaceAll(",", "")));
	// 		} else if (key.equals("hair_color")) {
	// 			setCorDoCabelo(value);
	// 		} else if (key.equals("skin_color")) {
	// 			setCorDaPele(value);
	// 		} else if (key.equals("eye_color")) {
	// 			setCorDosOlhos(value);
	// 		} else if (key.equals("birth_year")) {
	// 			setAnoNascimento(value);
	// 		} else if (key.equals("gender")) {
	// 			setGenero(value);
	// 		} else if (key.equals("homeworld")) {
	// 			setHomeworld(value);
	// 		} else {
	// 			break;
	// 		}
	// 	}
	// }

	void print() {
		cout << " ## " << nome;
		cout << " ## " << altura;
		cout << " ## " << peso;
		cout << " ## " << corDoCabelo;
		cout << " ## " << corDaPele;
		cout << " ## " << corDosOlhos;
		cout << " ## " << anoNascimento;
		cout << " ## " << genero;
		cout << " ## " << homeworld;
		cout << " ## " << endl;
	}

	Personagem clone() {
		Personagem clone;

		clone.nome = this->nome;
		clone.altura = this->altura;
		clone.peso = this->peso;
		clone.corDoCabelo = this->corDoCabelo;
		clone.corDaPele = this->corDaPele;
		clone.corDosOlhos = this->corDosOlhos;
		clone.anoNascimento = this->anoNascimento;
		clone.genero = this->genero;
		clone.homeworld = this->homeworld;

		return clone;
	}
};

#endif