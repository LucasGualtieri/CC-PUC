#include <stdio.h>

/*
	Crie uma função que receba dois parametros: um array e um valor do mesmo tipo do
	array. A função deverá preencher os elementos de array com esse valor.
	Não utilize índices para percorrer o array, apenas aritmética de ponteiros.
*/

// void PreenchimentoDaArray (int vetor[], int value) {
// 	int arrayLength = sizeof(*vetor) / 4;
// 	for (int i = 0; i < arrayLength; i++) {
// 		vetor[i] = value;
// 	}
// }

// void PreenchimentoDaMatriz (int **array, int value) {}

void PreenchimentoDoVetor(int* vetor, int value, int arrayLength) {

	for (int i = 0; i < arrayLength; i++) {
		*(vetor + i) = value;
	}
}

int main(void) {
	int vetor[5];
	int value = 3;
	int arrayLength = sizeof(vetor) / sizeof(int);

	// PreenchimentoDoVetor(array, value, arrayLength);
	PreenchimentoDoVetor(&vetor[0], value, arrayLength);

	for (int i = 0; i < arrayLength; i++) {
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}

	return 0;
}