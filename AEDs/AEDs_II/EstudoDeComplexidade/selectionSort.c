#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
	size_t size;
	int*   pointer;
} Array;

// arrayPrint para inteiros
void intArrayPrint(Array array) {

	printf("{ ");
	for (int i = 0; i < array.size; i++) {
		printf("%d", array.pointer[i]);
		printf("%s", i < array.size - 1 ? ", " : " }\n");
	}
}

void selectionSort(Array array) {
	int qtdComparacoes = 0, movimentacoes = 0;

	int* V = array.pointer;
	int	 N = array.size;

	for (int i = 0; i < N - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < N; j++) {
			qtdComparacoes++;
			if (V[menor] > V[j]) menor = j;
		}
		movimentacoes += 3;
		int swap = V[menor];
		V[menor] = V[i];
		V[i]	 = swap;
	}

	// // int LS			= N - 2;
	// int esquerda	= pow(N, 2) - N;
	// int meio		= (N - 1) * (N - 2) / 2;
	// int direita		= N - 1;
	// int teoriaLucas = esquerda - meio - direita;

	// printf("Esquerda: %d\n", esquerda);
	// printf("Meio: %d\n", meio);
	// printf("Direita: %d\n", direita);

	// printf("Comparações na Teoria Lucas: %d\n", teoriaLucas);
	printf("Comparações na Teoria: %d\n", ((int)pow(N, 2) - N) / 2);
	printf("Comparações na Prática: %d\n", qtdComparacoes);
	printf("Movimentações: %d\n", movimentacoes);
}

int main() {

	Array array;
	array.size	  = 1'024;
	array.pointer = (int*)malloc(array.size * sizeof(int));

	int contador = array.size;
	for (int i = 0; i < array.size; i++) {
		array.pointer[i] = contador--;
	}

	// intArrayPrint(array);

	selectionSort(array);

	// intArrayPrint(array);
}