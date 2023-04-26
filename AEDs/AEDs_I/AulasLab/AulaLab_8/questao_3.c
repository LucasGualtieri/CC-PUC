#include <stdio.h>

/*
	Implemente um programa que abra o arquivo texto
	(criado no exercício anterior) e imprima na tela
	o que está escrito no arquivo.
*/

int main(void) {
	FILE* file = fopen("text.txt", "r");
	char teste[30];
	char letra;

	fscanf(file, "%[^\n]", teste);
	printf("%s", teste);

	printf("\n---------------\n");

	file = fopen("text.txt", "r");

	while ((letra = fgetc(file)) != EOF) {
		printf("%c", letra);
	}

	return 0;
}