#include "ListaVeiculos.h"
#include "Veiculo.h"
#include <biblioteca_cpp.h>
#include <iomanip>

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
int OptionsMenu() {

	cout << "0 - Sair do programa." << endl;
	cout << "1 - Listar os veículos cadastrados." << endl;
	cout << "2 - Pesquisar um veículo (pela placa)." << endl;
	cout << "3 - Cadastrar um novo veículo." << endl;
	cout << "4 - Editar o cadastro de um veículo." << endl;
	cout << "5 - Remover um carro do cadastro." << endl;
	cout << "\nEscolha uma das opções acima: ";

	int escolha = ReadingChoice();

	return escolha;
}

// ANCHOR - Main
int main() {

	printColorBoldLn("------------ Cadastro de veículos ------------\n");

	ListaVeiculos lista;

	int escolha;
	while ((escolha = OptionsMenu())) {
		switch (escolha) {
		case 1:
			lista.listar();
			cout << endl;
			cout << endl;
			break;
		case 2:
			try {
				lista.listar();
				Veiculo temp = lista.pesquisar();
				clear();
				printColorBoldLn("------------ Veículo encontrado com sucesso! ------------\n", GREEN);
				lista.printHeader();
				temp.print(cout, lista.getLarguras());
				cout << endl;
				cout << endl;

			} catch (string erro) {
				cout << erro << endl;
			}
			break;
		case 3:
			lista.cadastrar();
			break;
		case 4:
			try {
				lista.listar();
				lista.editar(lista.pesquisar("\n\nDigite a placa do veículo à ser editado: "));
			} catch (string erro) {
				cout << erro << endl;
			}
			break;
		case 5:
			try {
				lista.listar();
				lista.remover(lista.pesquisar("\n\nDigite a placa do veículo à ser removido: "));
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

// Possível forma de imterromper o cadastro o pesquisar e o remover no meio
// Na hora de printar o carro depois da pesquisa por exemplo achar um jeito de printar as dimensoes correspondentes ao carro mostrado only