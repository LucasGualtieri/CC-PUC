#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// clear && gcc srSapo.c && ./a.out < pub.in

typedef struct Matriz {
	int **m, nLin, nCol;
} Matriz;

typedef struct Sapo {
	int nLin, nCol;
} Sapo;

Matriz newMatriz();
void closeMatriz(Matriz m);
void PreencherMatriz(Matriz m, Sapo* sapo);
void PrintMatriz(Matriz m);

int ValorPos(Matriz m, Sapo s) {

	int resultado = -1;

	// Testa se a posição é válida, ou seja, está dentro da matriz.
	if ((0 < s.nCol && s.nCol <= m.nCol + 1) && (0 < s.nLin && s.nLin <= m.nLin + 1)) {
		resultado = m.m[s.nCol - 1][s.nLin - 1];
	}

	return resultado;
}

bool EncontrarASapa(Matriz m, Sapo sapo) {

	bool achou = ValorPos(m, sapo) == 2; // Confere se achamos a Sapa.
	m.m[sapo.nCol - 1][sapo.nLin - 1] = -1; // Marcar onde já passou.

	// Se (ValorPos(m, sapo) > 0) então é uma pedra que o Sr. Sapo pode pular.

	sapo.nLin += 3; // Pular pra baixo.
	for (int i = 0; !achou && i < 3; i++) {
		if (ValorPos(m, sapo) > 0) achou = EncontrarASapa(m, sapo);
		sapo.nLin--;
	}

	sapo.nLin -= 3; // Pular pra cima.
	for (int i = 0; !achou && i < 3; i++) {
		if (ValorPos(m, sapo) > 0) achou = EncontrarASapa(m, sapo);
		sapo.nLin++;
	}

	sapo.nCol += 3; // Pular pra direita.
	for (int i = 0; !achou && i < 3; i++) {
		if (ValorPos(m, sapo) > 0) achou = EncontrarASapa(m, sapo);
		sapo.nCol--;
	}

	sapo.nCol -= 3; // Pular pra esquerda.
	for (int i = 0; !achou && i < 3; i++) {
		if (ValorPos(m, sapo) > 0) achou = EncontrarASapa(m, sapo);
		sapo.nCol++;
	}

	return achou;
}

int main() {

	Matriz m = newMatriz();

	Sapo sapo;
	PreencherMatriz(m, &sapo);

	printf("%c\n", EncontrarASapa(m, sapo) ? 'S' : 'N');

	closeMatriz(m);

	return 0;
}


Matriz newMatriz() {

	Matriz m;

	scanf("%d %d", &m.nCol, &m.nLin);

	m.m = malloc(m.nCol * sizeof(int*));
	for (int i = 0; i < m.nLin; i++) {
		m.m[i] = malloc(m.nLin * sizeof(int));
	}

	return m;
}

void PreencherMatriz(Matriz m, Sapo* sapo) {

	for (int i = 0; i < m.nLin; i++) {
		for (int j = 0; j < m.nCol; j++) {
			if (m.m[i][j] != 1) m.m[i][j] = 0;
		}
	}

	int qtdPedras;
	scanf("%d", &qtdPedras);

	for (int i = 0; i < qtdPedras; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		m.m[x - 1][y - 1] = 1; // Pedras indexadas em 1
	}

	scanf("%d %d", &sapo->nCol, &sapo->nLin); // Posição do Sapo

	Sapo sapa;
	scanf("%d %d", &sapa.nCol, &sapa.nLin); // Posição da Sapa
	m.m[sapa.nCol - 1][sapa.nLin - 1] = 2; // Posição da Sapa
}

void PrintMatriz(Matriz m) {
	
	printf("\n");

	for (int i = 0; i < m.nLin; i++) {
		for (int j = 0; j < m.nCol; j++) {
			printf("%d ", m.m[j][i]);
		}
		printf("\n");
	}
}

void closeMatriz(Matriz m) {
	for (int i = 0; i < m.nLin; i++) {
		free(m.m[i]);
	}
	free(m.m);
}