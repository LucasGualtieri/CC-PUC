#include <stdlib.h>

typedef struct Celula {
	int valor;
	struct Celula* bellow;

} Celula;

Celula newCelula(int valor, Celula* bellow) {

	Celula* celula = (Celula*)malloc(sizoeof(Celula));
	celula->valor = valor;
	celula->bellow = bellow;

	return celula;
}