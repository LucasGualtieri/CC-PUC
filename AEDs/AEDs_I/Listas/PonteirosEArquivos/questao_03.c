#include <stdio.h>

/*
	Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e
	troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo
	e, após a execução da função, A conterá o valor de B e B terá o valor de A.
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
	// int aux = *num1;
	// *num1 = *num2;
	// *num2 = aux;

	*num1 += *num2;
	*num2 = *num1 - *num2;
	*num1 -= *num2;
}