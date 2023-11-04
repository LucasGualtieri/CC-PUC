#ifndef LIB_C_FILA_CIRCULAR
#define LIB_C_FILA_CIRCULAR

#include "LibTP03.h"

typedef struct FilaCircular {

	Jogador *array;
	int primeiro, ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaCircular);
	void (*Mostrar) (struct FilaCircular);

	float (*Inserir) (Jogador, struct FilaCircular*);
	Jogador (*Remover) (struct FilaCircular*);

	void (*Close) (struct FilaCircular*);

} FilaCircular;

float GetMediaAlturasFilaCircular(FilaCircular fila) {
	float media = 0;
	int jogador = fila.primeiro;
	for (int i = 0; i < fila.size; i++) {
		media += fila.array[jogador].altura;
		jogador = (jogador + 1) % fila.maxSize;
	}
	return media / fila.size;
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.primeiro == fila.ultimo) {
		fprintf(stderr, "Erro ao mostrar: FilaCircular vazia.\n");
		return;
	}

	for (int i = 0, jogador = fila.primeiro; i < fila.size; i++) {
		printf("[%d] ## ", i);
		fila.array[i].Mostrar(fila.array[jogador]);
		jogador = (jogador + 1) % fila.maxSize;
	}
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

Jogador RemoverFilaCircular(FilaCircular* fila);

float InserirFilaCircular(Jogador jogador, FilaCircular* fila) {

	if ((fila->ultimo + 1) % fila->maxSize == fila->primeiro) {
		Jogador jogador = RemoverFilaCircular(fila);
		jogador.Close(jogador);
	}

	fila->size++;
	fila->array[fila->ultimo] = jogador.Clone(jogador);
	fila->ultimo = (fila->ultimo + 1) % fila->maxSize;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaCircular(FilaCircular* fila) {
	if (fila->primeiro == fila->ultimo) {
		fprintf(stderr, "Erro ao remover: Fila Circular vazia.\n");
		exit(0);
	}

	Jogador removido = fila->array[fila->primeiro];

	fila->size--;
	fila->primeiro = (fila->primeiro + 1) % fila->maxSize;

	return removido;
}

void CloseFilaCircular(FilaCircular* fila) {
	
	for (int i = 0, jogador = fila->primeiro; i < fila->size; i++) {
		fila->array[jogador].Close(fila->array[jogador]);
		jogador = (jogador + 1) % fila->maxSize;
	}

	free(fila->array);

	fila->maxSize = fila->size = 0;
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = fila.primeiro = fila.ultimo = 0;
	fila.maxSize = maxSize + 1;
	fila.array = (Jogador*)malloc((maxSize + 1) * sizeof(Jogador));

	fila.getMediaAlturas = GetMediaAlturasFilaCircular;
	fila.Mostrar = MostrarFilaCircular;

	fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;

	fila.Close = CloseFilaCircular;

	return fila;
}

#endif