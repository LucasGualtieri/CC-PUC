#include <biblioteca_c.h>

/*
	Escreva um programa em C para contar a
	quantidade de palavras de um arquivo texto.
*/

int main() {

	String fileDir = strdup("./text_files/");
	String fileName = strdup("text.txt");
	int cont = 0;

	FILE* file = fopen(pstrcat(fileDir, fileName), "r");

	while (!feof(file)) {
		char string[2000];
		fscanf(file, "%s", string);
		cont++;
	}

	printf("Foram lidas %d palavras do arquivo %s.", cont, fileName);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}