#include <stdio.h>

/*
	Crie um programa que contenha uma função que permita passar por parâmetro dois números
	inteiros A e B. A função deverá calcular a soma entre estes dois números e armazenar o resultado
	na variável A. Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro
	parâmetro. Imprima os valores de A e B na função principal.
*/

void Soma(int* a, int b);

int main(void) {

	int a, b;

	printf("Digite dois números inteiros separados por espaço: ");
	scanf("%d %d", &a, &b);

	printf("A: %d\nB: %d\n", a, b);

	Soma(&a, b);

	printf("%d + %d = %d", a - b, b, a);

	return 0;
}

void Soma(int* a, int b) {
	*a += b;
}