#ifndef LIB_CELULA_H
#define LIB_CELULA_H

#include "../LibTP04.h"

typedef struct Celula {
	Jogador jogador;
	struct Celula *esq, *dir;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* esq, Celula* dir) {
	Celula* celula = malloc(sizeof(Celula));

	celula->jogador = jogador.Clone(jogador);
	celula->esq = esq;
	celula->dir = dir;
	celula->Close = CloseCelula;

	return celula;
}

#endif