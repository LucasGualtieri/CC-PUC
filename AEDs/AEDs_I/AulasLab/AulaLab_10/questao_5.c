#include <stdio.h>
#include <string.h>

/*
	Faça um algoritmo para percorrer uma
	string e retornar se a string é ou não palindromo.
*/

int Palindromo(char* nome) {
	for (int i = strlen(nome) - 1, j = 0; i > 0; i--) {
		if (nome[i] == nome[j]) {
			j++;
		} else {
			printf("Não é palíndromo");
			return 0;
		}
	}
	printf("É palíndromo");
	return 0;
}

int main() {
	char nome[] = "arara";

	Palindromo(nome);

	return 0;
}