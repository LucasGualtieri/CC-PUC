#include <stdio.h>
#include <string.h>

/*
	Faça um algoritmo para percorrer uma string
	e imprimir a quantidade de caracteres minusculos.
*/

int main(void) {
	char str[] = "aBCDeFgHIJKLmNOPQrSTUvWXuZ";

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			printf("%c", str[i]);
		}
	}

	return 0;
}