#ifndef LIB_C_FILA_FLEX
#define LIB_C_FILA_FLEX

#include "Celulas/Celula.h"

typedef struct FilaFlex {

	Celula *primeiro, *ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaFlex);
	void (*Mostrar) (struct FilaFlex);

	float (*Inserir) (Jogador, struct FilaFlex*);
	Jogador (*Remover) (struct FilaFlex*);

	void (*Close) (struct FilaFlex*);

} FilaFlex;

float GetMediaAlturasFilaFlex(FilaFlex fila) {
	float media = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->dir) {
		media += i->jogador.altura;
	}
	return media / fila.size;
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

float InserirFilaFlex(Jogador jogador, FilaFlex* fila) {

	if (fila->size == fila->maxSize) { jogador.Close(fila->Remover(fila)); }

	if (fila->size == 0) fila->primeiro = fila->ultimo = newCelula(jogador, NULL);
	else fila->ultimo = fila->ultimo->dir = newCelula(jogador, NULL);
	fila->size++;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaFlex(FilaFlex* fila) {

	if (fila->size == 0) {
		fprintf(stderr, "Erro ao remover: Fila Flex vazia.\n");
		exit(0);
	}

	fila->size--;
	Celula* removida = fila->primeiro;
	fila->primeiro = removida->dir;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarFilaFlex(FilaFlex fila) {
	if (fila.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila Flex vazia.\n");
		exit(0);
	}

	int contador = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->dir) {
		printf("[%d] ## ", contador++);
		i->jogador.Mostrar(i->jogador);
	}

}

void CloseFilaFlex(FilaFlex* fila) {
	
	Celula* i = fila->primeiro;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->dir;
		tmp->Close(tmp);
	}

	fila->maxSize = fila->size = 0;
}

FilaFlex newFilaFlex(size_t maxSize) {

	FilaFlex fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.primeiro = fila.ultimo = NULL;
	fila.maxSize = maxSize;

	fila.getMediaAlturas = GetMediaAlturasFilaFlex;
	fila.Mostrar = MostrarFilaFlex;

	fila.Inserir = InserirFilaFlex;
	fila.Remover = RemoverFilaFlex;

	fila.Close = CloseFilaFlex;

	return fila;
}

#endif