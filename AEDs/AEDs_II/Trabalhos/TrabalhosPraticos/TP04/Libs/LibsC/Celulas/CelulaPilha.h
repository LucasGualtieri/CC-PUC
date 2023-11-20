#ifndef LIB_CELULA_PILHA_H
#define LIB_CELULA_PILHA_H

#include "../LibTP03.h"

typedef struct CelulaPilha {
	Jogador jogador;
	struct CelulaPilha *baixo;
	void (*Close) (struct CelulaPilha*);
} CelulaPilha;

void CloseCelulaPilha(CelulaPilha* CelulaPilha) {
	CelulaPilha->jogador.Close(CelulaPilha->jogador);
	free(CelulaPilha);
}

CelulaPilha* newCelulaPilha(Jogador jogador, CelulaPilha* baixo) {
	CelulaPilha* CelulaPilha = malloc(sizeof(CelulaPilha));

	CelulaPilha->jogador = jogador.Clone(jogador);
	CelulaPilha->Close = CloseCelulaPilha;

	return CelulaPilha;
}

#endif