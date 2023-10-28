#include "../Libs/LibTP03.h"

// clear && gcc TP03Q10.c && ./a.out < pub.in > result.txt

void InserirERemover(PilhaFlex* pilha, Lista BD) {

	Split split = splitSpace();

	if (split.array[0][0] == 'I') {
		int id = atoi(split.array[1]);
		pilha->Inserir(BD.Get(id, BD), pilha);
	} else {
		Jogador jogador = pilha->Remover(pilha);
		printf("(R) %s\n", jogador.nome);
		jogador.Close(jogador);
	}

}

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	PilhaFlex pilha = newPilhaFlex();

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		pilha.Inserir(BD.Get(id, BD), &pilha);
	}

	int numberOfActions = readInt();

	for (int i = 0; i < numberOfActions; i++) {
		InserirERemover(&pilha, BD);
	}

	pilha.Mostrar(pilha);

	pilha.Close(&pilha);
	BD.Close(&BD);

}