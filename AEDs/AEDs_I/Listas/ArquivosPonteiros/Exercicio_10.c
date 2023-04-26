#include <limits.h>
#include <stdio.h>

/*
	Considere um arquivo texto que armazene números em ponto flutuante em cada uma de suas
	linhas. Escreva um programa em C que determine o valor máximo, o valor mínimo e a média
	desses valores armazenados no arquivo. Imprima esses valores na tela.
*/

int main() {

	float max = (float)INT_MIN, min = (float)INT_MAX;
	float media, floatChar, soma = 0;
	char caractere;
	int cont = 0;

	FILE* file = fopen("text_files/exercicio10.txt", "r");

	do {
		fscanf(file, "%f", &floatChar);
		printf("%d° %g\n", cont + 1, floatChar);
		if (floatChar < min) min = floatChar;
		if (floatChar > max) max = floatChar;
		soma += floatChar;
		cont++;
	} while ((caractere = fgetc(file)) != EOF);

	media = soma / (float)cont;

	printf("Média: %g\n", media);
	printf("Máximo: %g\n", max);
	printf("Mínimo: %g\n", min);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}