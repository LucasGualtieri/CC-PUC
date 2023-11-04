#include "../Libs/LibsC/LibTP03.h"
#include "../Libs/LibsC/FilaFlex.h"

// clear && gcc TP03Q07.c && ./a.out < pub.in > result.txt

void InserirERemover(FilaFlex* fila, BD BD) {

	Split split = splitSpace();

	if (split.array[0][0] == 'I') {
		int id = atoi(split.array[1]);
		printf("%.f\n", fila->Inserir(BD.Get(id, BD), fila));
	} else {
		Jogador jogador = fila->Remover(fila);
		printf("(R) %s\n", jogador.nome);
		jogador.Close(jogador);
	}

}

int main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	FilaFlex fila = newFilaFlex(5);

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		printf("%.f\n", fila.Inserir(BD.Get(id, BD), &fila));
	}

	int numberOfActions = readInt();

	for (int i = 0; i < numberOfActions; i++) {
		InserirERemover(&fila, BD);
	}

	fila.Mostrar(fila);

	fila.Close(&fila);
	BD.Close(&BD);

}