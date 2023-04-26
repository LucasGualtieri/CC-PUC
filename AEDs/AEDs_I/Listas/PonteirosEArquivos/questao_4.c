#include <stdio.h>

/*
	Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores
	de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável.
	Escreva o conteúdo das 2 variáveis na tela.
*/

void PassagemPorReferencia(int* num1, int* num2);

int main() {

	int num1, num2;

	printf("Digite dois números inteiros separados por espaço: ");
	scanf("%d %d", &num1, &num2);

	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);

	printf("-------------\n");

	PassagemPorReferencia(&num1, &num2);

	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

void PassagemPorReferencia(int* num1, int* num2) {

	if (*num2 > *num1) {
		// int aux = *num1;
		// *num1 = *num2;
		// *num2 = aux;

		*num1 += *num2;
		*num2 = *num1 - *num2;
		*num1 -= *num2;
	}
}