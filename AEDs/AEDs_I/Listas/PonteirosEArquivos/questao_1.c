#include <stdio.h>

/*
	Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real,
	e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando
	os ponteiros. Imprima os valores das variáveis antes e após a modificação.
*/

void PassagemPorReferencia(int* inteiroPtr, float* realPtr, char* caracterePtr);

int main() {

	int inteiro = 0, *inteiroPtr = &inteiro;
	float real = 0, *realPtr = &real;
	char caractere = '0', *caracterePtr = &caractere;

	printf("inteiro: %d\n", inteiro);
	printf("real: %.2f\n", real);
	printf("caractere: %c\n", caractere);

	printf("-------------\n");

	*inteiroPtr = 1;
	*realPtr = 1;
	*caracterePtr = '1';

	// PassagemPorReferencia(&inteiro, &real, &caractere);

	printf("inteiro: %d\n", inteiro);
	printf("real: %.2f\n", real);
	printf("caractere: %c\n", caractere);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

void PassagemPorReferencia(int* inteiroPtr, float* realPtr, char* caracterePtr) {
	*inteiroPtr = 1;
	*realPtr = 1;
	*caracterePtr = '1';
}