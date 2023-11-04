#include "../Libs/LibsC/LibTP03.h"
#include "../Libs/LibsC/Lista.h"

// clear && gcc TP03Q02.c && ./a.out < pub.in > result.txt

void RemoverEPrintar(Jogador jogador) {
	printf("(R) %s\n", jogador.nome);
	jogador.Close(jogador);
}

void InserirERemover(Lista* lista, BD BD) {

	Split split = splitSpace();
	int id = atoi(split.array[1]);

	if (!strcmp(split.array[0], "II")) {
		lista->InserirInicio(BD.Get(id, BD), lista);
	} else if (!strcmp(split.array[0], "IF")) {
		lista->InserirFim(BD.Get(id, BD), lista);
	} else if (!strcmp(split.array[0], "I*")) {
		id = atoi(split.array[2]);
		lista->Inserir(split.array[1], BD.Get(id, BD), lista);
	} else if (!strcmp(split.array[0], "RI")) {
		RemoverEPrintar(lista->RemoverInicio(lista));
	} else if (!strcmp(split.array[0], "RF")) {
		RemoverEPrintar(lista->RemoverFim(lista));
	} else {
		RemoverEPrintar(lista->Remover(split.array[1], lista));
	}

}

int main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista lista = newLista(250);

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.InserirFim(BD.Get(id, BD), &lista);
	}

	int numberOfActions = readInt();

	for (int i = 0; i < numberOfActions; i++) {
		InserirERemover(&lista, BD);
	}

	lista.Mostrar(lista);

	lista.Close(&lista);
	BD.Close(&BD);

}