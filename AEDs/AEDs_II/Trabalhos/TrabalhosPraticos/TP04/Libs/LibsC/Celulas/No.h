#ifndef LIB_NO_H
#define LIB_NO_H

#include "../LibTP04.h"
// #include "../AVL.h"

typedef struct No {
	Jogador jogador;
	int nivel;
	struct No *esq, *dir;
	void (*setNivel) (struct No*);
	void (*Close) (struct No*);
} No;

void SetNivelNo(No* no) {
	no->nivel = max(alturaEsq(no), alturaDir(no)) + 1;
}

void CloseNo(No* No) {
	No->jogador.Close(No->jogador);
	free(No);
}

No* newNo(Jogador jogador, No* esq, No* dir) {

	No* no = malloc(sizeof(No));

	no->jogador = jogador.Clone(jogador);
	no->esq = esq;
	no->dir = dir;
	no->setNivel = SetNivelNo;
	no->Close = CloseNo;

	return no;
}

#endif