#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pesquisaBinaria(int* array, int N, int x) {
	int qtdComparacoes = 0, movimentacoes = 0;

	bool resp = false;
	int	 direita = N - 1, esquerda = 0, meio, elemento;
	while (esquerda <= direita) {
		meio = (esquerda + direita) / 2;
		elemento = array[meio];
		movimentacoes++;
		if (elemento == x) {
			resp = true;
			esquerda = direita + 1;
		} else if (elemento > x) {
			esquerda = meio + 1;
		} else {
			direita = meio - 1;
		}
	}
	
	printf("%s\n", resp ? "Achou" : "Nao a achou");
	printf("movimentacoes: %d\n", movimentacoes);
}

int main() {

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	pesquisaBinaria(array, 15, 16);
}