#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// clear && gcc srSapoAlternativo.c && ./a.out < pub.in

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
bool EncontrarASapa(Matriz m, Sapo sapo);

int ValorPos(Matriz m, Sapo s) {	

	int resultado = -1;

	// Testa se a posição é válida, ou seja, está dentro da matriz.
	if ((0 < s.nCol && s.nCol <= m.nCol) && (0 < s.nLin && s.nLin <= m.nLin)) {
		resultado = m.m[s.nCol - 1][s.nLin - 1];
	}

	return resultado;
}

// Se (ValorPos(m, sapo) > 0) então é uma pedra que o Sr. Sapo pode pular.
bool EncontrarASapaAux(int nLin, int nCol, Sapo sapo, bool achou, Matriz m) {

	sapo.nLin += nLin;
	sapo.nCol += nCol;

	for (int i = 0; !achou && i < 3; i++) {
		if (ValorPos(m, sapo) > 0) achou = EncontrarASapa(m, sapo);
		if (nLin != 0) sapo.nLin = (nLin > 0) ? sapo.nLin - 1 : sapo.nLin + 1;
		else sapo.nCol = (nCol > 0) ? sapo.nCol - 1 : sapo.nCol + 1;
	}

	return achou;
}

bool EncontrarASapa(Matriz m, Sapo sapo) {

	bool achou = ValorPos(m, sapo) == 2; // Confere se achamos a Sapa.
	m.m[sapo.nCol - 1][sapo.nLin - 1] = -1; // Marcar onde já passou.

	achou = EncontrarASapaAux(3, 0, sapo, achou, m); // Pulando para baixo.
	achou = EncontrarASapaAux(-3, 0, sapo, achou, m); // Pulando para cima.
	achou = EncontrarASapaAux(0, 3, sapo, achou, m); // Pulando para direita.
	achou = EncontrarASapaAux(0, -3, sapo, achou, m); // Pulando para esquerda.

	return achou;
}

int main() {

	Matriz m = newMatriz();

	Sapo sapo;
	PreencherMatriz(m, &sapo);

	// PrintMatriz(m);	

	printf("%c\n", EncontrarASapa(m, sapo) ? 'S' : 'N');

	// PrintMatriz(m);
	
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
			m.m[i][j] = 0;
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
			printf("%2d ", m.m[j][i]);
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