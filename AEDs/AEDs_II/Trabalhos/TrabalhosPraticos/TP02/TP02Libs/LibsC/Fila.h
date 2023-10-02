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

	void (*Sort)(struct Fila);

	void (*ImportDataBase) (literal filePath, struct Fila*);
	Jogador (*Get)(int id, struct Fila);

	void (*ToggleShow)(struct Fila*);
	void (*Mostrar)(struct Fila);
	void (*Close)(struct Fila*);

} Fila;

void InserirFila(Jogador jogador, Fila* fila) {

	if (fila->maxSize == 0) {
		fprintf(stderr, "Erro ao inserir: Fila fechada.\n");
		return;
	} else if (fila->size == fila->maxSize) {
		fprintf(stderr, "Erro ao inserir: Fila cheia.\n");
		return;
	}

	fila->array[fila->size++] = jogador.Clone(jogador);

	if (fila->showOnUpdate) fila->Mostrar(*fila);

}

void SortFila(Fila fila);

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
	
	for (int i = 0; i < fila->size; i++) {
		fila->array[i].Close(fila->array[i]);
	}

	free(fila->array);
	
	fila->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Fila* BD) {

	FILE* CSV;
	if (!(CSV = fopen(filePath, "r"))) {
		printf("Erro: Falha ao abrir players.csv\n");
		exit(0);
	}

	char inputCSV[STR_MAX_LEN];
	readStr(CSV, inputCSV); // Despresando o header do .csv
	
	Jogador jogador;

	while (!feof(CSV)) {

		// No estado atual o split retorna uma possível linha vazia quando o arquivo tem uma linha vazia no final
		Split array = newSplit(CSV);

		jogador = newJogador();
		jogador.Construtor(array, &jogador);

		BD->Inserir(jogador, BD);

	}
}

Jogador GetFila(int id, Fila fila) { return fila.array[id]; }

Fila newFila(size_t maxSize) {

	Fila fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (Jogador*)malloc(maxSize * sizeof(Jogador));
	fila.showOnUpdate = false;

	fila.Inserir = InserirFila;
	fila.Remover = RemoverFila;

	fila.Sort = SortFila;

	fila.ImportDataBase = ImportDataBaseBD;
	fila.Get = GetFila;

	fila.ToggleShow = ToggleShowOnUpdateFila;
	fila.Mostrar = MostrarFila;
	fila.Close = CloseFila;

	return fila;
}