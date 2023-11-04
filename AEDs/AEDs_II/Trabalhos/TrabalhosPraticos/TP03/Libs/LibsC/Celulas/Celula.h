#ifndef LIB_CELULA_H
#define LIB_CELULA_H

#include "../LibTP03.h"

typedef struct Celula {
	Jogador jogador;
	struct Celula *dir;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* dir) {
	Celula* celula = malloc(sizeof(Celula));

	celula->jogador = jogador.Clone(jogador);
	celula->dir = dir;
	celula->Close = CloseCelula;

	return celula;
}

#endif