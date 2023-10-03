#ifndef LISTA_H
#define LISTA_H

#include "LibTP02.h"
#include "Split.h"
#include "Jogador.h"

typedef struct Lista {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir)(Jogador jogador, struct Lista*);
	Jogador (*Remover)(struct Lista*);

	void (*Sort)(struct Lista);

	void (*ImportDataBase) (literal filePath, struct Lista*);
	Jogador (*Get)(int id, struct Lista);

	void (*ToggleShow)(struct Lista*);
	void (*Mostrar)(struct Lista);
	void (*Close)(struct Lista*);

} Lista;

void InserirLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

	if (lista->showOnUpdate) lista->Mostrar(*lista);

}

void SortLista(Lista lista);

void ToggleShowOnUpdateLista(Lista* lista) {
	lista->showOnUpdate = lista->showOnUpdate ? false : true;
}

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		lista.array[i].Mostrar(lista.array[i]);
	}
}

void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
	lista->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Lista* BD) {

	FILE* CSV;
	if (!(CSV = fopen(filePath, "r"))) {
		printf("Erro: Falha ao abrir players.csv\n");
		exit(0);
	}

	char inputCSV[STR_MAX_LEN];
	readStr(CSV, inputCSV); // Despresando o header do .csv
	
	Jogador jogador;

	while (!feof(CSV)) {

		Split array = newSplit(CSV);

		jogador = newJogador();
		jogador.Construtor(array, &jogador);

		BD->Inserir(jogador, BD);

	}

}

Jogador GetLista(int id, Lista lista) { return lista.array[id]; }

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (Jogador*)malloc(maxSize * sizeof(Jogador));
	lista.showOnUpdate = false;

	lista.Inserir = InserirLista;

	lista.Sort = SortLista;

	lista.ImportDataBase = ImportDataBaseBD;
	lista.Get = GetLista;

	lista.ToggleShow = ToggleShowOnUpdateLista;
	lista.Mostrar = MostrarLista;
	lista.Close = CloseLista;

	return lista;
}

#endif