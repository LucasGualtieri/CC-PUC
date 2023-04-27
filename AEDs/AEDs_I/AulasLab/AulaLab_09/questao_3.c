#include <stdio.h>
#include <stdlib.h>

/*
	Faça um programa que cria uma matriz, alocando-a dinamicamente em memória.
	Preencha essa matriz com valores a sua escolha na função Main. Após, faça
	um PROCEDIMENTO	que recebe como parâmetros a matriz, o número de linhas da
	matriz e o número de colunas da matriz e imprima os valores da matriz na tela.
	BONUS) Fazer uma função que receba uma matriz como parâmetro e a salve em um arquivo.
*/

void MatrizArquivo(int linhas, int colunas, int** matriz) {
	// printf("\n");

	FILE* file = fopen("text.txt", "w");

	for (int i = 0; i < linhas; i++) {
		for (int k = 0; k < colunas; k++) {
			// printf("Matriz: %d\n", matriz[i][k]);
			fprintf(file, "Matriz[%d][%d]: %d\n", i, k, matriz[i][k]);
		}
	}
}

int main(void) {
	int linhas, colunas;

	printf("Digite o número de linhas da matriz: ");
	scanf("%d", &linhas);
	printf("Digite o número de colunas da matriz: ");
	scanf("%d", &colunas);

	int* matriz[linhas];

	// Contrução da matriz dinâmica
	for (int i = 0; i < linhas; i++) {
		matriz[i] = malloc(colunas * sizeof(int));
	}

	// Preenchimento da matriz a partir do input do usuário
	for (int i = 0; i < linhas; i++) {
		for (int k = 0; k < colunas; k++) {
			printf("Linha[%d] -> Coluna[%d]: ", i + 1, k + 1);
			scanf("%d", &matriz[i][k]);
		}
	}

	printf("\n");

	// Print dos elementos da matriz
	for (int i = 0; i < linhas; i++) {
		for (int k = 0; k < colunas; k++) {
			printf("Matriz[%d][%d]: %d\n", i, k, matriz[i][k]);
		}
	}

	MatrizArquivo(linhas, colunas, matriz);

	return 0;
}