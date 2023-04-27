#include <stdio.h>
// #include <string.h>

/*
	Faça um algoritmo para percorrer uma string
	e retornar o reverso da string.
*/

int main(void) {
	char str[] = "String";

	for (int i = strlen(str) - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}

	return 0;
}