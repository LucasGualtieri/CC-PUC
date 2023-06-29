#include <biblioteca_cpp.h>
#include <iomanip>
#include <split.h>

// ANCHOR - Class Veiculo
class Veiculo {

	string placa, marca, modelo, obs;
	char   tipo;
	int	   ano;
	float  preco;
	size_t precoLen, marcaLen, modeloLen, tipoLen;

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

		ostringstream oss;
		oss << fixed << setprecision(2) << preco;

		setPrecoLen(oss.str().length());
	}

	void setPreco(float preco) {
		this->preco = preco;
	}

	void setPrecoLen(size_t precoLen) {
		this->precoLen = precoLen;
	}

	size_t getPrecoLen() {
		return precoLen;
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

		setMarcaLen(marca.length());
	}

	void setMarca(string marca) {
		this->marca = marca;
	}

	void setMarcaLen(size_t marcaLen) {
		this->marcaLen = marcaLen;
	}

	size_t getMarcaLen() {
		return marcaLen;
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

		setModeloLen(modelo.length());
	}

	void setModelo(string modelo) {
		this->modelo = modelo;
	}

	void setModeloLen(size_t modeloLen) {
		this->modeloLen = modeloLen;
	}

	size_t getModeloLen() {
		return modeloLen;
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

	void setTipo(char tipoLen) {
		this->tipoLen = tipoLen;
	}

	void setTipoLen(size_t tipoLen) {
		this->tipoLen = tipoLen;
	}

	size_t getTipoLen() {
		return tipoLen;
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
		cout << " | Preço: " << fixed << setprecision(2) << getPreco();
		cout << " | Marca: " << getMarca();
		cout << " | Modelo: " << getModelo();
		cout << " | Tipo: " << getTipo();
		cout << " | Observação: ";
		if (!getObs().empty()) {
			cout << getObs();
		} else {
			cout << "Sem observações";
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
	size_t	 larguraPreco, larguraMarca, larguraModelo, larguraTipo;

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

	// ANCHOR - SetLarguras
	void setLarguras() {

		larguraPreco  = 0;
		larguraMarca  = 7; // Não pode ser menor que 7???
		larguraModelo = 8; // Não pode ser menor que 8???
		larguraTipo	  = 0; // Não pode ser menor que 8???

		for (int i = 0; i < Veiculo::contador; i++) {
			size_t len;
			if ((len = array[i].getPrecoLen()) > larguraPreco) larguraPreco = len;
			if ((len = array[i].getMarcaLen()) > larguraMarca) larguraMarca = len;
			if ((len = array[i].getModeloLen()) > larguraModelo) larguraModelo = len;
			if ((len = array[i].getTipoLen()) > larguraTipo) larguraTipo = len;
		}

		larguraPreco++;
		larguraMarca++;
		larguraModelo++;
		larguraTipo++;
	}

	// ANCHOR - GetDataBase
	void getDataBase() {
		fstream dataBase("DB.txt");

		readString(dataBase); // Skipping header

		for (int i = 0; !dataBase.eof(); i++) {

			Split veiculo(readString(dataBase), "|");

			veiculo.trimAll();

			array[i].setPlaca(veiculo[0]);
			array[i].setAno(stoi(veiculo[1]));
			array[i].setPreco(stof(veiculo[2]));
			array[i].setPrecoLen(veiculo[2].length());
			array[i].setMarca(veiculo[3]);
			array[i].setMarcaLen(veiculo[3].length());
			array[i].setModelo(veiculo[4]);
			array[i].setModeloLen(veiculo[4].length());
			array[i].setTipo(veiculo[5][0]);
			array[i].setTipoLen(veiculo[5].length());
			array[i].setObs(veiculo[6]);

			Veiculo::contador++;
		}

		setLarguras();

		dataBase.close();
	}

	// ANCHOR - GetFromFile
	void getFromFile() {
		FILE* DB = fopen("DB.txt", "r");

		// char carroX[500];

		char  placa[10], modelo[50], marca[50], obs[50];
		char  tipo[6];
		int	  ano;
		float preco;
		bool  fim = false;

		for (int i = 0; !feof(DB); i++) {

			fscanf(DB, "%[^;]%*c", placa);
			fscanf(DB, "%d%*c", &ano);
			fscanf(DB, "%f%*c", &preco);
			fscanf(DB, "%[^;]%*c", marca);
			fscanf(DB, "%[^;]%*c", modelo);
			fscanf(DB, "%[^;]%*c", tipo);
			fscanf(DB, "%[^;]%*c", obs);

			if (getc(DB) == EOF) break; // para comer o '\n'

			// printf("%s\n", placa);

			string objPlaca(placa);
			array[i].setPlaca(objPlaca);

			array[i].setAno(ano);

			array[i].setPreco(preco);

			string objMarca(marca);
			array[i].setMarca(objMarca);

			string objModelo(modelo);
			array[i].setModelo(objModelo);

			array[i].setTipo(tipo[0]);

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

		setLarguras();

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
		fstream dataBase("DB.txt", ios::out);

		dataBase << "PLACA" << right << setw(5) << "| ";
		dataBase << "ANO" << right << setw(4) << "| ";
		dataBase << "PREÇO" << right << setw(larguraPreco - 3) << " | ";
		dataBase << "MARCA" << right << setw(larguraMarca - 5) << " | ";
		dataBase << "MODELO" << right << setw(larguraModelo - 6) << "| ";
		dataBase << "TIPO" << right << setw(larguraPreco - 6) << " | ";
		dataBase << "OBSERVAÇÃO";
		dataBase << endl;

		for (int i = 0; i < Veiculo::contador; i++) {

			dataBase << array[i].getPlaca() << " | ";
			dataBase << array[i].getAno() << " | ";
			dataBase << fixed << setprecision(2) << array[i].getPreco() << right << setw(larguraPreco - array[i].getPrecoLen() + 2) << "| ";
			dataBase << array[i].getMarca() << right << setw(larguraMarca - array[i].getMarcaLen()) << " | ";
			dataBase << array[i].getModelo() << right << setw(larguraModelo - array[i].getModeloLen()) << " | ";
			dataBase << array[i].getTipo() << right << setw(larguraPreco - array[i].getTipoLen() - 2) << " | ";
			if (array[i].getObs().length() > 0) {
				dataBase << array[i].getObs();
			} else {
				dataBase << "Sem observações";
			}

			if (i < Veiculo::contador - 1) dataBase << endl;
		}

		dataBase.close();
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