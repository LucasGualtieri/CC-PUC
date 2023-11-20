#ifndef LIB_C_LISTA
#define LIB_C_LISTA

#include "LibTP03.h"

typedef struct Lista {

	Jogador *array;
	int maxSize, size;

	void (*Mostrar) (struct Lista);

	void (*InserirInicio) (Jogador, struct Lista*);
	void (*InserirFim) (Jogador, struct Lista*);
	void (*Inserir) (String pos, Jogador, struct Lista*);
	Jogador (*RemoverInicio) (struct Lista*);
	Jogador (*RemoverFim) (struct Lista*);
	Jogador (*Remover) (String pos, struct Lista*);

	void (*Close) (struct Lista*);

} Lista;

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		printf("[%d] ## ", i);
		lista.array[i].Mostrar(lista.array[i]);
	}
}

// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

void InserirInicioLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;

	for (int i = lista->size; i > 0; i--) array[i] = array[i - 1];

	array[0] = jogador.Clone(jogador);

	lista->size++;

}

void InserirFimLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

}

void InserirLista(String posStr, Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;
	int pos = atoi(posStr);

	for (int i = lista->size; i > pos; i--) array[i] = array[i - 1];

	array[pos] = jogador.Clone(jogador);

	lista->size++;

}

Jogador RemoverInicioLista(Lista* lista) {
	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	Jogador removido = array[0].Clone(array[0]);

	for (int i = 0; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}

Jogador RemoverFimLista(Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	return lista->array[--lista->size];
}

Jogador RemoverLista(String posStr, Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	int pos = atoi(posStr);
	Jogador removido = array[pos];

	for (int i = pos; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}

void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
	lista->maxSize = lista->size = 0;
}

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (Jogador*)malloc(maxSize * sizeof(Jogador));

	lista.Mostrar = MostrarLista;

	lista.InserirInicio = InserirInicioLista;
	lista.InserirFim = InserirFimLista;
	lista.Inserir = InserirLista;
	lista.RemoverInicio = RemoverInicioLista;
	lista.RemoverFim = RemoverFimLista;
	lista.Remover = RemoverLista;

	lista.Close = CloseLista;

	return lista;
}

#endif