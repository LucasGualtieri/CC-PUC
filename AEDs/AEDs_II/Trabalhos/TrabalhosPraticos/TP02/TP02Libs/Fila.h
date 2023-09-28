#include "LibTP02.h"
#include "Jogador.h"
#include "Split.h"

const Jogador ERRO = { -0x7fffffff }; // Setta o Id

typedef struct Fila {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir)(Jogador jogador, struct Fila*);
	Jogador (*Remover)(struct Fila*);

	void (*ImportDataBase) (literal filePath, struct Fila*);
	Jogador (*Get) (int id, struct Fila);

	void (*ToggleShow) (struct Fila*);
	void (*Mostrar)(struct Fila);
	void (*Close)(struct Fila*); // Implementar o Jogador.close(); Para dar free nas strings

} Fila;

void InserirFila(Jogador jogador, Fila* fila) {

	if (fila->maxSize == 0) {
		fprintf(stderr, "Erro ao inserir: Fila fechada.\n");
		return;
	} else if (fila->size == fila->maxSize) {
		fprintf(stderr, "Erro ao inserir: Fila cheia.\n");
		return;
	}

	fila->array[fila->size++] = jogador;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

}

Jogador RemoverFila(Fila* fila) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (fila->maxSize == 0) {
		fprintf(stderr, "Erro ao remover: Fila fechada.\n");
		return ERRO;
	} else if (fila->size == 0) {
		fprintf(stderr, "Erro ao remover: Fila vazia.\n");
		return ERRO;
	}

	Jogador removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

	return removido;
}

void ToggleShowOnUpdateFila(Fila* fila) {
	fila->showOnUpdate = fila->showOnUpdate ? false : true;
}

void MostrarFila(Fila fila) {

	// listaJogadores.printPlayer(id, BD); // Loopar pelo id

	if (fila.maxSize == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila fechada.\n");
		return;
	} else if (fila.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila vazia.\n");
		return;
	}

	for (int i = 0; i < fila.size; i++) {
		fila.array[i].Mostrar(fila.array[i]);
	}
}

void CloseFila(Fila* fila) {
	free(fila->array);
	// For pra dar free em todos os jogadores
	fila->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Fila* BD) {

	// printf("filePath: %s\n", filePath);

	FILE* CSV = fopen(filePath, "r");
	char inputCSV[STR_MAX_LEN];
	readStr(CSV, inputCSV); // Despresando o header do .csv
	
	while (!feof(CSV)) {

		// printf("inputCSV: %s\n", inputCSV);

		// No estado atual o split retorna uma possível linha vazia quando o arquivo tem uma linha vazia no final
		Split array = newSplit(CSV, ",");
		Jogador jogador = newJogador();

		jogador.Construtor(array, &jogador);
		BD->Inserir(jogador, BD);

		// jogador.Mostrar(jogador);
	}
}

Jogador GetFila(int id, Fila fila) {
	return fila.array[id];
}

Fila newFila(size_t maxSize) {

	Fila fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (Jogador*)malloc(maxSize * sizeof(Jogador));
	fila.showOnUpdate = false;

	fila.Inserir = InserirFila;
	fila.Remover = RemoverFila;

	fila.ImportDataBase = ImportDataBaseBD;
	fila.Get = GetFila;

	fila.ToggleShow = ToggleShowOnUpdateFila;
	fila.Mostrar = MostrarFila;
	fila.Close = CloseFila;

	return fila;
}