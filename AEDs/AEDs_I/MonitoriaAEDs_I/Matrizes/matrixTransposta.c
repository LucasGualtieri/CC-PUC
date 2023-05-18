#include <biblioteca_c.h>

#define MAX_LIN 3
#define MAX_COL 3

void PreencheMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
	int contador = 1;
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = contador++;
		}
	}
}

void PrintaMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void MatrizTransposta(int matriz1[MAX_LIN][MAX_COL], int matriz2[MAX_COL][MAX_LIN]) {
	for (int i = 0; i < MAX_LIN; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			matriz2[i][j] = matriz1[j][i];
		}
	}
}

int main() {

	int matriz1[MAX_LIN][MAX_COL];
	int matriz2[MAX_COL][MAX_LIN];

	PreencheMatriz(MAX_LIN, MAX_COL, matriz1);
	PreencheMatriz(MAX_COL, MAX_LIN, matriz2);

	PrintaMatriz(MAX_LIN, MAX_COL, matriz1);
	printf("-----\n");
	PrintaMatriz(MAX_COL, MAX_LIN, matriz2);

	printf("\n*****\n\n");

	MatrizTransposta(matriz1, matriz2);

	PrintaMatriz(MAX_LIN, MAX_COL, matriz1);
	printf("-----\n");
	PrintaMatriz(MAX_COL, MAX_LIN, matriz2);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}