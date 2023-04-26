#include <stdio.h>

/*
	Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em
	seguida, compare seus endereços e exiba o conteúdo do maior endereço.
*/

void PassagemPorReferencia(int* inteiroPtr, float* realPtr, char* caracterePtr);

int main() {

	int num1, num2;

	printf("Digite dois números inteiros separados por espaço: ");
	scanf("%d %d", &num1, &num2);

	printf("&num1: %p\n", &num1);
	printf("&num2: %p\n", &num2);

	printf("O valor da variável de maior endereço é: %d", &num1 > &num2 ? num1 : num2);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}