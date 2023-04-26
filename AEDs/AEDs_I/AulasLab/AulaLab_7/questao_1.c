#include <stdio.h>

int main(void) {
	int inteiro = 1, *ptrInteiro = &inteiro;
	float real = 1.0, *ptrReal = &real;
	char caractere = 'a', *ptrCaractere = &caractere;

	printf("\nInteiro: %d", inteiro);
	printf("\nReal: %.1f", real);
	printf("\nChar: %c", caractere);

	*ptrInteiro = 2;
	*ptrReal = 2.0;
	*ptrCaractere = 'b';

	printf("\n\nInteiro: %d", inteiro);
	printf("\nReal: %.1f", real);
	printf("\nChar: %c", caractere);

	return 0;
}