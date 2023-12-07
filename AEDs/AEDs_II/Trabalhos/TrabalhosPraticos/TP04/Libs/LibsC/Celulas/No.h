#ifndef LIB_NO_H
#define LIB_NO_H

#include "../LibTP04.h"

typedef struct No {
	Jogador jogador;
	int nivel;
	struct No *esq, *dir;
	void (*Close) (struct No*);
} No;

void CloseNo(No* No) {
	No->jogador.Close(No->jogador);
	free(No);
}

No* newNo(Jogador jogador, No* esq, No* dir) {

	No* no = malloc(sizeof(No));
	
	no->jogador = jogador.Clone(jogador);
	no->esq = esq;
	no->dir = dir;
	no->Close = CloseNo;

	return no;
}

#endif