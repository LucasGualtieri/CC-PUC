#include <stdlib.h>

typedef struct Celula {
	int valor;
	struct Celula* prox;
} Celula;

Celula* newCelula(int valor, Celula* prox) {

	Celula* celula = (Celula*)malloc(sizeof(Celula));
	celula->valor = valor;
	celula->prox = prox;

	return celula;
}