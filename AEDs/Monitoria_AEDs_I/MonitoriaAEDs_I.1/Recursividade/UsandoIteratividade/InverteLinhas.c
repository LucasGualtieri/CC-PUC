#include <biblioteca_c.h>

#define NLINHAS 3
#define NCOLUNAS 3

void PreencheMatriz(float matriz[NLINHAS][NCOLUNAS]) {
	int contador = 1;
	for (int i = 0; i < NLINHAS; i++) {
		for (int j = 0; j < NCOLUNAS; j++) {
			matriz[i][j] = contador++;
		}
	}
}

void PrintaMatriz(float matriz[NLINHAS][NCOLUNAS]) {
	for (int i = 0; i < NLINHAS; i++) {
		for (int j = 0; j < NCOLUNAS; j++) {
			printf("%g ", matriz[i][j]);
		}
		printf("\n");
	}
}

void InverteLinhasIterativo(int linhaX, int linhaY, float matriz[NLINHAS][NCOLUNAS]) {
	for (int i = 0; i < NCOLUNAS; i++) {
		float aux = matriz[linhaX][i];
		matriz[linhaX][i] = matriz[linhaY][i];
		matriz[linhaY][i] = aux;
	}
}

void InverteLinhas(int linhaX, int linhaY, float matriz[NLINHAS][NCOLUNAS], int i) {

	if (i < NCOLUNAS) {
		float aux = matriz[linhaX][i];
		matriz[linhaX][i] = matriz[linhaY][i];
		matriz[linhaY][i] = aux;
		InverteLinhas(linhaX, linhaY, matriz, ++i);
	}
}

int main() {
	float matriz[NLINHAS][NCOLUNAS];
	int linhaX = 0, linhaY = 2;

	PreencheMatriz(matriz);

	PrintaMatriz(matriz);

	// InverteLinhasIterativo(linhaX, linhaY, matriz);
	InverteLinhas(linhaX, linhaY, matriz, 0);

	printf("-----\n");
	PrintaMatriz(matriz);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}