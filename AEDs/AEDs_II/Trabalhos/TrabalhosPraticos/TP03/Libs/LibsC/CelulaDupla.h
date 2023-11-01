#ifndef LIB_CELULA_DUPLA_H
#define LIB_CELULA_DUPLA_H

typedef struct Celula {
	Jogador jogador;
	struct Celula *prox, *ant;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* ant, Celula* prox) {
	Celula* celula = malloc(sizeof(Celula));

	celula->jogador = jogador.Clone(jogador);
	celula->ant = ant;
	celula->prox = prox;
	celula->Close = CloseCelula;

	return celula;
}

#endif