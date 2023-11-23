#ifndef LIB_CELULA_DUPLA_H
#define LIB_CELULA_DUPLA_H

#include "../LibTP03.h"

typedef struct CelulaDupla {
	Jogador jogador;
	struct CelulaDupla *esq, *dir;
	void (*Close) (struct CelulaDupla*);
} CelulaDupla;

void CloseCelulaDupla(CelulaDupla* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

CelulaDupla* newCelulaDupla(Jogador jogador, CelulaDupla* esq, CelulaDupla* dir) {
	CelulaDupla* celula = malloc(sizeof(CelulaDupla));

	celula->jogador = jogador.Clone(jogador);
	celula->esq = esq;
	celula->dir = dir;
	celula->Close = CloseCelulaDupla;

	return celula;
}

#endif