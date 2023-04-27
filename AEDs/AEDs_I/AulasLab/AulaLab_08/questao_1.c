#include <stdio.h>

/*
	Crie um programa que escreva de 1 até 10
	em um arquivo, armazenando um número por linha.
*/

int main(void) {
	FILE* file = fopen("text.txt", "w");

	for (int i = 1; i <= 10; i++) {
		fprintf(file, "%d\n", i);
	}

	return 0;
}