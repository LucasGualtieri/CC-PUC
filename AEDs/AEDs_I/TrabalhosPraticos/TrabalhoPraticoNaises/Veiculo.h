#ifndef VEICULO_H
#define VEICULO_H

#include <biblioteca_cpp.h>
#include <iomanip>

typedef struct Larguras {
	size_t preco, marca, modelo, tipo;
} Larguras;

class Veiculo {

	// ANCHOR - Atributos
	string		  placa, marca, modelo, obs;
	char		  tipo;
	int			  ano;
	float		  preco;
	size_t		  precoLen, marcaLen, modeloLen, tipoLen;
	static size_t contador;

  public:
	static void incrementCount() {
		contador++;
	}
	static void decrementCount() {
		contador--;
	}
	static size_t getCount() {
		return contador;
	}

	// ANCHOR - Set / Get Placa
	void setPlaca() {

		string placa;
		bool   invalid = false;

		string errorMsg = RED + "Placa inválida, " + RESET + "tente novamente: ";

		cout << "Placa: ";
		do {
			if (invalid) cout << errorMsg;
			placa = readString(cin);
		} while ((invalid = placa.length() != 7));

		this->placa = placa;
	}

	void setPlaca(string placa) {
		this->placa = placa;
	}

	string getPlaca() { return placa; }

	// -----------------------------------------
	// ANCHOR - Set / Get Ano

	void setAno() {

		int	 ano;
		bool invalid = false;

		string errorMsg = RED + "Ano inválido, " + RESET + "tente novamente: ";

		cout << "Ano de fabricação: ";
		do {
			if (invalid) cout << errorMsg;
			ano = readInt(errorMsg);
		} while ((invalid = ano < 1'886 || ano > 2'023));

		this->ano = ano;
	}

	void setAno(int ano) {
		this->ano = ano;
	}

	int getAno() { return ano; }

	// -----------------------------------------
	// ANCHOR - Set / Get Preço

	void setPreco() {
		float preco;
		bool  invalid = false;

		string errorMsg = RED + "Preço inválido, " + RESET + "tente novamente: ";

		cout << "Preço: ";
		do {
			if (invalid) cout << errorMsg;
			preco = readFloat("", errorMsg);
		} while ((invalid = preco <= 0.0));

		this->preco = preco;
	}

	void setPreco(float preco) {
		this->preco = preco;
	}

	size_t getPrecoLen() {
		ostringstream oss;
		oss << fixed << setprecision(2) << getPreco();
		return oss.str().length();
	}

	float getPreco() { return preco; }

	// -----------------------------------------
	// ANCHOR - Set / Get Marca

	void setMarca() {
		string marca;
		bool   invalid = false;

		string errorMsg = RED + "Marca inválida, " + RESET + "tente novamente: ";

		cout << "Marca: ";
		do {
			if (invalid) cout << errorMsg;
			marca = readString(cin);
		} while ((invalid = marca.length() == 0));

		this->marca = marca;
	}

	void setMarca(string marca) {
		this->marca = marca;
	}

	string getMarca() { return marca; }

	// -----------------------------------------
	// ANCHOR - Set / Get Modelo

	void setModelo() {
		string modelo;
		bool   invalid = false;

		string errorMsg = RED + "Modelo inválido, " + RESET + "tente novamente: ";

		cout << "Modelo: ";
		do {
			if (invalid) cout << errorMsg;
			modelo = readString(cin);
		} while ((invalid = modelo.length() == 0));

		this->modelo = modelo;
	}

	void setModelo(string modelo) {
		this->modelo = modelo;
	}

	string getModelo() { return modelo; }

	// -----------------------------------------
	// ANCHOR - Set / Get Tipo

	void setTipo() {

		char tipo;
		bool invalid = false;

		string errorMsg = RED + "Tipo inválido, " + RESET + "tente novamente: ";

		cout << "Tipo do veículo ([C] para carro e [M] para moto): ";
		do {
			if (invalid) cout << errorMsg;
			cin >> tipo;
			flush();
		} while ((invalid = !strchr("CcMm", tipo)));

		this->tipo = tipo;
	}

	void setTipo(char tipo) {
		this->tipo = tipo;
	}

	string getTipo() {
		if (tipo == 'C' || tipo == 'c') {
			return "Carro";
		} else {
			return "Moto";
		}
	}

	// -----------------------------------------
	// ANCHOR - Set / Get Observação

	void setObs() {
		cout << "Observação (Opcional): ";
		this->obs = readString(cin);
	}

	void setObs(string obs) {
		this->obs = obs;
	}

	string getObs() { return obs; }

	// -----------------------------------------

	// ANCHOR - Print
	void print(Larguras larguras, ostream& stream = cout) {

		stream << setw(8) << left << getPlaca();
		stream << "| " << setw(5) << left << getAno();
		stream << "| " << setw(larguras.preco) << left << fixed << setprecision(2) << getPreco();
		stream << "| " << setw(larguras.marca) << left << getMarca();
		stream << "| " << setw(larguras.modelo) << left << getModelo();
		stream << "| " << setw(larguras.tipo) << left << getTipo();
		if (!getObs().empty()) {
			stream << "| " << getObs();
		} else {
			stream << "| Sem observações";
		}
	}
};

// Contador is private, so it's only accessable outside of the scope of the classe in its initialization
size_t Veiculo::contador; // default initialization to zero

/*
	In this case, Veiculo::contador is zero-initialized because
	it was not explicitly initialized. However, it's generally
	a good practice to explicitly initialize static data members
	to avoid potential bugs and make the code more readable.
*/

#endif