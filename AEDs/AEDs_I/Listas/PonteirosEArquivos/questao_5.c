#include <stdio.h>

/*
	Elaborar um programa que leia dois valores inteiros (A e B). Em seguida Faça uma função que
	retorne a soma do dobro dos dois números lidos. A função deverá armazenar o dobro de A na
	própria variável A e o dobro de B na própria variável B.
*/

int SomaDoDobro(int* num1, int* num2);

int main() {

	int num1, num2;

	printf("Digite dois números inteiros separados por espaço: ");
	scanf("%d %d", &num1, &num2);

	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);

	printf("-------------\n");

	SomaDoDobro(&num1, &num2);

	// printf("%d + %d = %d\n", num1, num2, SomaDoDobro(&num1, &num2)); // Sem chamar na linha 26.
	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);
	printf("%d + %d = %d\n", num1 /= 2, num2 /= 2, SomaDoDobro(&num1, &num2) / 2);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

int SomaDoDobro(int* num1, int* num2) {

	*num1 *= 2;
	*num2 *= 2;

	return *num1 + *num2;
}