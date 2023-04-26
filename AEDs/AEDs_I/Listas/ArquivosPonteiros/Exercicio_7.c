#include <stdio.h>
#include <string.h>

/*
	Escreva um programa em C para contar a quantidade de palavras de um arquivo texto.
*/

int main() {
	char fileDir[] = "./text_files/";
	char fileName[] = "text.txt";
	char caractere;
	int cont = 0;
	int cont1 = 0;

	FILE* file = fopen(strcat(fileDir, fileName), "r");

	while (caractere != EOF) {
		caractere = getc(file);

		if (caractere == ' ' || caractere == EOF) {
			cont++;
		}

		if (cont1 == 0 && caractere == EOF) {
			cont = 0;
			break;
		}
		cont1++;
	}

	printf("Foram lidas %d palavras do arquivo %s.", cont, fileName);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}