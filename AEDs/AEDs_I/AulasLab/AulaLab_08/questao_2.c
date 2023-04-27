#include <stdio.h>

/*
	Crie um programa que receba um texto do usíario
	e grave o texto em um arquivo.
*/

int main(void) {
	char texto[80];

	FILE* file = fopen("text.txt", "w");

	printf("Digite um texto para ser\ngravado em um arquivo: ");
	scanf("%[^\n]", texto);

	fprintf(file, "%s", texto);
	return 0;
}