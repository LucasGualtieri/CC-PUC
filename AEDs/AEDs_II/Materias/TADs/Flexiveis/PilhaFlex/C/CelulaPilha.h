#ifndef CELULA_PILHA_H
#define CELULA_PILHA_H

#include <stdlib.h>

typedef struct CelulaPilha {
	int value;
	struct CelulaPilha* prox;
} CelulaPilha;

CelulaPilha* newCelulaPilha(int value, CelulaPilha* top) {
	CelulaPilha* new = malloc(sizeof(CelulaPilha));
	new->prox = top;
	new->value = value;
	return new;
}

#endif