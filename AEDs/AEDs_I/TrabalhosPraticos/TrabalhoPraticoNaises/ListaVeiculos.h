#ifndef LISTA_VEICULOS_H
#define LISTA_VEICULOS_H

#include "Veiculo.h"
#include <biblioteca_cpp.h>
#include <iomanip>
#include <split.h>

// typedef struct Larguras {
// 	size_t preco, marca, modelo, tipo;
// } Larguras;

class ListaVeiculos {
	Veiculo* array;
	Larguras larguras;

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

		larguras.preco	= 5; // Não pode ser menor que 6
		larguras.marca	= 5; // Não pode ser menor que 6
		larguras.modelo = 6; // Não pode ser menor que 7
		larguras.tipo	= 4; // Não pode ser menor que 4

		for (int i = 0; i < Veiculo::contador; i++) {
			size_t len;
			if ((len = array[i].getPrecoLen()) > larguras.preco) larguras.preco = len;
			if ((len = array[i].getMarcaLen()) > larguras.marca) larguras.marca = len;
			if ((len = array[i].getModeloLen()) > larguras.modelo) larguras.modelo = len;
			if ((len = array[i].getTipoLen()) > larguras.tipo) larguras.tipo = len;
		}

		if (larguras.preco >= 5) larguras.preco++; // ++ para considerar o espaço
		if (larguras.marca >= 5) larguras.marca++;
		if (larguras.modelo >= 6) larguras.modelo++;
		larguras.tipo++; // Doesn't need an if statement because the minimum size is the same size as the TIPO.len() ???
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

		char  placa[10], modelo[50], marca[50], obs[50], tipo[6];
		int	  ano;
		float preco;

		for (int i = 0; !feof(DB); i++) {

			fscanf(DB, "%[^;]%*c", placa);
			fscanf(DB, "%d%*c", &ano);
			fscanf(DB, "%f%*c", &preco);
			fscanf(DB, "%[^;]%*c", marca);
			fscanf(DB, "%[^;]%*c", modelo);
			fscanf(DB, "%[^;]%*c", tipo);
			fscanf(DB, "%[^;]%*c", obs);

			if (getc(DB) == EOF) break; // para comer o '\n'

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

			Veiculo::contador++;
		}

		fclose(DB);
	}

	// ANCHOR - Cadastrar
	void cadastrar() {

		// array = realloc(array, (size + 1) * sizeof(veiculos));

		if (Veiculo::contador == 500) { // cont == size ARRUMAR
			printColorLn("atingiu o maximo de veiculos cadastrados", RED);
			return;
		}

		clear();

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

		clear();

		printColorBoldLn("------- Veículo cadastrado com sucesso! -------\n", GREEN);
	}

	// ANCHOR - Remover
	void remover(Veiculo remover) {

		remover.print();

		// deletar o carro do arquivo
		if (Veiculo::contador == 0) {
			printColorLn("erro lista vazia", RED);
			return;
		}

		// buscando a posicao do carro a ser excluido
		bool found = false;
		int	 i;
		for (i = 0; !found && i < Veiculo::contador - 1; i++) {
			if (array[i].getPlaca() == remover.getPlaca()) {
				found	 = true;
				array[i] = array[Veiculo::contador - 1];
			}
		}
		Veiculo::contador--;

		clear();

		printColorBoldLn("------------ Carro removido com sucesso! ------------\n", GREEN);
	}

	void editar(Veiculo& veiculo) {
		clear();

		printColorBoldLn("------------ Editando o veículo ------------\n");

		cout << "Preencha as especificações do veículo: \n\n";

		// array[Veiculo::contador].setPlaca();

		veiculo.setAno();

		veiculo.setPreco();

		veiculo.setMarca();

		veiculo.setModelo();

		veiculo.setTipo();

		veiculo.setObs();

		printColorBoldLn("------------ Editado com sucesso ------------\n", GREEN);
		clear();
	}

	void listarDep() {

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

		clear();

		for (int i = 0; i < Veiculo::contador; i++) {
			// cout << "[" << i + 1 << "] - ";
			array[i].print();
		}
		cout << endl;

		// cout << endl;
	}

	void printHeader(ostream& stream = cout) {
		stream << setw(8) << left << "PLACA";
		stream << "| " << setw(5) << left << "ANO";
		stream << "| " << setw(larguras.preco + 1) << left << "PREÇO";
		stream << "| " << setw(larguras.marca) << left << "MARCA";
		stream << "| " << setw(larguras.modelo) << left << "MODELO";
		stream << "| " << setw(larguras.tipo) << left << "TIPO";
		stream << "| OBSERVAÇÃO";
		stream << endl;
	}

	// ANCHOR - Listar
	void listar() {

		clear();

		printColorBoldLn("------------ Lista de veículos cadastrados ------------\n");

		printHeader(cout);

		for (int i = 0; i < Veiculo::contador; i++) {
			array[i].print(cout, larguras);
			if (i < Veiculo::contador - 1) cout << endl;
		}
	}

	// ANCHOR - Save
	void save() {
		fstream dataBase("DB.txt", ios::out);

		printHeader(dataBase);

		for (int i = 0; i < Veiculo::contador; i++) {
			array[i].print(dataBase, larguras);
			if (i < Veiculo::contador - 1) dataBase << endl;
		}

		dataBase.close();
	}

	// ANCHOR - Pesquisar
	Veiculo& pesquisar(string msg = "\n\nDigite a placa do veículo à ser encontrado: ") {

		printColorBold(msg);

		string placa = readString(cin);

		for (int i = 0; i < Veiculo::contador; i++) {
			if (array[i].getPlaca() == placa) {
				return array[i];
			}
		}

		throw string("\n" + RED + "Erro: " + RESET + "Carro não encontrado!\n");
	}
};

#endif