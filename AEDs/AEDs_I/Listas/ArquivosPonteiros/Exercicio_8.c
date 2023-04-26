#include <stdio.h>
#include <string.h>

/*
	Escreva um programa em C que abra um arquivo texto e que conte a quantidade
	de caracteres armazenados nele. Imprima o número na tela. O programa deve
	solicitar ao usuário que digite	o nome do arquivo.
*/

int main() {
	char caractere, fileName[30], *fileDir = "text_files/";
	int cont = 0;

	printf("Digite o nome do arquivo: ");
	scanf("%s", fileName);

	char concatDirName[strlen(fileDir) + strlen(fileName)];
	strcpy(concatDirName, fileDir);
	strcat(concatDirName, fileName);
	strcat(concatDirName, ".txt");

	FILE* file = fopen(concatDirName, "r");

	while (!(file = fopen(concatDirName, "r"))) {
		printf("Arquivo não existe!\n");
		printf("Digite o nome do arquivo: ");
		scanf("%s", fileName);
		strcpy(concatDirName, fileDir);
		strcat(concatDirName, fileName);
		strcat(concatDirName, ".txt");
	}

	while ((caractere = getc(file)) != EOF) {
		if (caractere != '\n') cont++;
	}

	printf("Foram lidos %d caracteres do arquivo %s.", cont, fileName);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}