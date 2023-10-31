#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// clear && gcc Bingo.c && ./a.out < pub.in > result.txt

void PreencherMatriz(int nLinhas, int nColunas, int** matriz);
int** AllocarMatriz(int nLinhas, int nColunas);

void RodadaDoBingo(int nLinhas, int nColunas, int** matriz) {

	int numeroDaVez;
	scanf("%d", &numeroDaVez);

	for (int i = 0; i < nLinhas; i++) {
		for (int j = 0; j < nColunas; j++) {
			if (matriz[i][j] == numeroDaVez) matriz[i][j] = 0;
		}
	}

}

bool HaVencedor(int nLinhas, int nColunas, int** matriz) {

	bool resultado = false;

	for (int i = 0; i < nLinhas; i++) {
		int contador = 0;
		for (int j = 0; j < nColunas; j++) {
			if (matriz[i][j] == 0) contador++;
		}
		if (contador == nColunas) {
			printf("%d ", i + 1);
			resultado = true;
		}
	}

	return resultado;
}

int main() {

	int nLinhas, nColunas, U;

	scanf("%d %d %d", &nLinhas, &nColunas, &U);

	int** matriz = AllocarMatriz(nLinhas, nColunas);

	PreencherMatriz(nLinhas, nColunas, matriz);

	bool jogoEmAndamento = true;

	for (int i = 0; i < U && jogoEmAndamento; i++) {
		RodadaDoBingo(nLinhas, nColunas, matriz);
		jogoEmAndamento = !HaVencedor(nLinhas, nColunas, matriz);
	}

}

void PreencherMatriz(int nLinhas, int nColunas, int** matriz) {

	for (int i = 0; i < nLinhas; i++) {
		for (int j = 0; j < nColunas; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}

}

int** AllocarMatriz(int nLinhas, int nColunas) {

	int** matriz = malloc(nLinhas * sizeof(int*));

	for (int i = 0; i < nLinhas; i++) {
		matriz[i] = malloc(nColunas * sizeof(int));
	}

	return matriz;

}