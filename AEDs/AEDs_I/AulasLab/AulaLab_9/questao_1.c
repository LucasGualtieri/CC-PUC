#include <stdio.h>

/*
	Crie um programa que contenha um array de inteiros contendo 5 elementos. Leia esse
	array do teclado e imprima o dobro de cada valor lido.
*/

int main(void) {
	int dobro[5];
	// sizeof(dobro[0]) funciona também
	int arrayLength = sizeof(dobro) / sizeof(int);

	for (int i = 0; i < arrayLength; i++) {
		printf("Escreva o %d° número: ", i + 1);
		scanf("%d", &dobro[i]);
	}

	printf("\n");

	for (int i = 0; i < arrayLength; i++) {
		printf("O dobro do %d° número é: %d\n", i + 1, dobro[i] * 2);
	}

	return 0;
}