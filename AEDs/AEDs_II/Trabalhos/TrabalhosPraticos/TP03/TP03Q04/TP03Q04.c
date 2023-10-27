#include "../Libs/LibTP03.h"

// clear && gcc TP03Q04.c && ./a.out < pub.in > result.txt

void InserirERemover(FilaCircular* fila, Lista BD) {

	Split split = splitSpace();

	if (split.array[0][0] == 'I') {
		int id = atoi(split.array[1]);
		fila->Inserir(BD.Get(id, BD), fila);
	} else {
		Jogador jogador = fila->Remover(fila);
		printf("(R) %s\n", jogador.nome);
		jogador.Close(jogador);
	}

}

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	FilaCircular fila = newFilaCircular(6);

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		fila.Inserir(BD.Get(id, BD), &fila);
	}

	int numberOfActions = readInt();

	for (int i = 0; i < numberOfActions; i++) {
		InserirERemover(&fila, BD);
	}

	fila.Mostrar(fila);

	fila.Close(&fila);
	BD.Close(&BD);

}