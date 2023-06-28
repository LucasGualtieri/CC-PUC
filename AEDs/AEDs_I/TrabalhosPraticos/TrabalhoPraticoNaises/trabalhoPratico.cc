#include <biblioteca_cpp.h>
#include <iomanip>

typedef struct Larguras {
	size_t placa, ano, marca, modelo, preco, tipo, obs;
} Larguras;

Larguras setLarguras() {
	Larguras larguras;

	larguras.placa	= 10;
	larguras.ano	= 10;
	larguras.marca	= 10;
	larguras.modelo = 10;
	larguras.preco	= 10;
	larguras.tipo	= 10;
	larguras.obs	= 10;

	return larguras;
}

// ANCHOR - Class Veiculo
class Veiculo {

	string placa, modelo, marca, obs;
	char   tipo;
	int	   ano;
	float  preco;

  public:
	static int contador;

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

	void setAno() {

		int	 ano;
		bool invalid = false;

		string errorMsg = RED + "Ano inválido, " + RESET + "tente novamente: ";

		cout << "Ano de fabricação: ";
		do {
			if (invalid) cout << errorMsg;
			ano = readInt("", errorMsg);
		} while ((invalid = ano > 2'023));

		this->ano = ano;
	}

	void setAno(int ano) {
		this->ano = ano;
	}

	int getAno() { return ano; }

	// -----------------------------------------

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

	float getPreco() { return preco; }

	// -----------------------------------------

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

	void setObs() {
		cout << "Observação (Opcional): ";
		this->obs = readString(cin);
	}

	void setObs(string obs) {
		this->obs = obs;
	}

	string getObs() { return obs; }

	// -----------------------------------------

	// ANCHOR veiculoprint
	void print() {

		cout << "Placa: " << getPlaca();
		cout << " | Ano de fabricação: " << getAno();
		printf(" | Preço: %.2lf", getPreco());
		// cout << " | Preço: " << getPreco();
		cout << " | Marca: " << getMarca();
		cout << " | Modelo: " << getModelo();
		cout << " | Tipo: " << getTipo();
		string obs;
		if ((obs = getObs()).length() > 0) {
			cout << " | Observação: " << obs;
		}
		cout << endl;

		// Larguras larguras = setLarguras();

		// cout << left << setw(larguras.placa) << placa;
		// cout << setw(larguras.ano) << ano;
		// cout << setw(larguras.preco) << fixed << setprecision(2) << preco;
		// cout << setw(larguras.marca) << marca;
		// cout << setw(larguras.modelo) << modelo;
		// cout << setw(larguras.tipo) << tipo;
		// cout << setw(larguras.obs) << obs;
		// cout << endl;
	}
};

int Veiculo::contador = 0;

class ListaVeiculos {
	Veiculo* array;

  public:
	ListaVeiculos() {
		array = new Veiculo[500];
		getDataBase();
	}

	ListaVeiculos(size_t size) {
		array = new Veiculo[size];
	}

	~ListaVeiculos() {
		delete[] array;
	}

	// falta o editar e o ler do arquivo e passar para o vetor

	// ANCHOR - GetDataBase
	void getDataBase() {
		FILE* DB = fopen("veiculos.txt", "r");

		// char carroX[500];

		bool fim = false;

		for (int i = 0; !feof(DB); i++) {

			char  placa[10], modelo[50], marca[50], obs[50];
			char  tipo;
			int	  ano;
			float preco;

			fscanf(DB, "%[^;]%*c %d%*c %f%*c %[^;]%*c %[^;]%*c %c%*c %[^;]%*c", placa, &ano, &preco, marca, modelo, &tipo, obs);
			getc(DB);

			// printf("%s\n", placa);

			string objPlaca(placa);
			array[i].setPlaca(objPlaca);

			array[i].setAno(ano);

			array[i].setPreco(preco);

			string objMarca(marca);
			array[i].setMarca(objMarca);

			string objModelo(modelo);
			array[i].setModelo(objModelo);

			array[i].setTipo(tipo);

			string objObs(obs);
			array[i].setObs(objObs);

			// cout << "Looping..." << endl;

			Veiculo::contador++;
		}

		fclose(DB);
	}

	// ANCHOR - Cadastrar
	void cadastrar() {

		if (Veiculo::contador == 500) {
			printColorLn("atingiu o maximo de veiculos cadastrados", RED);
			return;
		}

		clrscreen();

		printColorBoldLn("------------ Cadastrando novo veículo ------------\n");

		cout << "Preencha as especificações do veículo: \n\n";

		array[Veiculo::contador].setPlaca();

		array[Veiculo::contador].setAno();

		array[Veiculo::contador].setPreco();

		array[Veiculo::contador].setMarca();

		array[Veiculo::contador].setModelo();

		array[Veiculo::contador].setTipo();

		array[Veiculo::contador].setObs();

		Veiculo::contador++;

		clrscreen();

		printColorBoldLn("------- Veículo cadastrado com sucesso! -------\n", GREEN);
	}

	// ANCHOR - Excluir
	void excluir(Veiculo excluir) {

		excluir.print();

		// deletar o carro do arquivo
		if (Veiculo::contador == 0) {
			printColorLn("erro lista vazia", RED);
			return;
		}

		// buscando a posicao do carro a ser excluido
		bool found = false;
		int	 i;
		cout << Veiculo::contador << endl;
		cout << array[0].getPlaca() << endl;
		for (i = 0; !found && i < Veiculo::contador - 1; i++) {
			cout << "A" << endl;
			if (array[i].getPlaca() == excluir.getPlaca()) {
				found	 = true;
				array[i] = array[Veiculo::contador - 1];
			}
		}
		Veiculo::contador--;

		printColorLn("carro excluido com sucesso!", GREEN);
	}

	// ANCHOR - Listar
	void listar() {

		// Larguras larguras = setLarguras();

		if (Veiculo::contador == 0) {
			cout << "Não há carros cadastrados no sistema." << endl;
			return;
		}

		// printColorBoldLn("X carros cadastrados:\n\n");

		// cout << endl;
		// cout << left << setw(larguras.placa) << "Placa | ";
		// cout << setw(larguras.ano) << "Ano | ";
		// cout << setw(larguras.preco) << "Preço | ";
		// cout << setw(larguras.marca) << "Marca | ";
		// cout << setw(larguras.modelo) << "Modelo | ";
		// cout << setw(larguras.tipo) << "Tipo | ";
		// cout << setw(larguras.obs) << "Observação";
		// cout << endl;
		// cout << endl;

		clrscreen();

		for (int i = 0; i < Veiculo::contador; i++) {
			// cout << "[" << i + 1 << "] - ";
			array[i].print();
		}
		cout << endl;

		// cout << endl;
	}

	// ANCHOR - Save
	void save() {
		// para printar no arquivo
		FILE* arquivo = fopen("veiculos.txt", "w");
		for (int i = 0; i < Veiculo::contador; i++) {
			fprintf(arquivo, "%s;", array[i].getPlaca().c_str());
			fprintf(arquivo, "%d;", array[i].getAno());
			fprintf(arquivo, "%.2f;", array[i].getPreco());
			fprintf(arquivo, "%s;", array[i].getModelo().c_str());
			fprintf(arquivo, "%s;", array[i].getMarca().c_str());
			fprintf(arquivo, "%s;", array[i].getTipo().c_str());
			fprintf(arquivo, "%s;\n", array[i].getObs().c_str());
		}

		fclose(arquivo);
	}

	// ANCHOR - Pesquisar
	Veiculo pesquisar() {
		// pesquisa atravez da placa do carro

		printColorLn("digite sua placa", YELLOW);

		string placa = readString(cin);

		for (int i = 0; i < Veiculo::contador; i++) {
			if (array[i].getPlaca() == placa) {
				return array[i];
			}
		}

		throw string(RED + "Erro: " + RESET + "Carro não encontrado!");
	}
};

// ANCHOR - ReadingChoice
int ReadingChoice() {
	int	 choice;
	bool invalid = false;

	string errorMsg = RED + "Entrada inválida, " + RESET + "tente novamente: ";

	do {
		if (invalid) {
			cout << "Valor inválido, tente novamente: ";
		}
		choice = readInt("", errorMsg);
	} while ((invalid = choice < 0 || choice > 5));

	return choice;
}

// ANCHOR - OptionsMenu
int OptionsMenu(ListaVeiculos& lista) {

	cout << "0 - Sair do programa." << endl;
	cout << "1 - Listar os veículos cadastrados." << endl;
	cout << "2 - Pesquisar um veículo (pela placa)." << endl;
	cout << "3 - Cadastrar um novo veículo." << endl;
	cout << "4 - Editar o cadastro de um veículo." << endl;
	cout << "5 - Excluir um carro do cadastro." << endl;
	cout << "\nEscolha uma das opções acima: ";

	int escolha = ReadingChoice();

	return escolha;
}

// ANCHOR - Main
int main() {

	printColorBoldLn("------------ Cadastro de veículos ------------\n");

	ListaVeiculos lista;

	int escolha;
	while ((escolha = OptionsMenu(lista))) {
		switch (escolha) {
		case 1:
			lista.listar();
			break;
		case 2:
			try {
				lista.pesquisar().print();
			} catch (string erro) {
				cout << erro << endl;
			}
			break;
		case 3:
			lista.cadastrar();
			break;
		case 4:
			/* para ediatr o cadastro dos veiculos */
			break;
		case 5:
			try {
				lista.excluir(lista.pesquisar());
			} catch (string erro) {
				cout << erro << endl;
			}
			break;
		}
	}

	lista.save();

	printColorBold("\n------- Obrigado por usar o programa! -------\n\n");

	return 0;
}