#include <stdio.h>
#include <string.h>

/*
	Escreva um programa em C que solicite ao usuário a digitação do nome de um arquivo texto já
	existente, e que então gere um outro arquivo, que será uma cópia do primeiro.
*/

int exists(char* fileDir, char* fileName) {
	char dirNameConcat[strlen(fileDir) + strlen(fileName) + 4];
	strcpy(dirNameConcat, fileDir);
	strcat(dirNameConcat, fileName);
	strcat(dirNameConcat, ".txt");
	// printf("%s", dirNameConcat);

	FILE* file;

	if ((file = fopen(dirNameConcat, "r"))) {
		fclose(file);
		return 1;
	}
	return 0;
}

int main() {
	char str[1000], fileName[80], fileDir[80] = "text_files/", fileDirCopy[80] = "text_files/";

	printf("Digite o nome do arquivo: ");
	scanf("%s", fileName);

	while (!exists(fileDir, fileName)) {
		printf("Arquivo não existe!\n");
		printf("Digite o nome do arquivo: ");
		scanf("%s", fileName);
	}

	char fileCopyName[80];
	strcpy(fileCopyName, fileName);
	strcat(fileCopyName, "_copy.txt");

	strcat(fileName, ".txt");
	// char fileName1[30]; // Tive que fazer isso pq por algum motivo o fileName esta mudando de valor
	// strcpy(fileName1, fileName);

	strcat(fileDirCopy, fileName);

	FILE* file = fopen(fileDirCopy, "r");

	strcpy(fileDirCopy, fileDir);
	strcat(fileDirCopy, fileCopyName);

	FILE* fileCopy = fopen(fileDirCopy, "w");

	while (fgets(str, 1000, file) != NULL) {
		fprintf(fileCopy, "%s", str);
		// printf("%s", str);
	}

	printf("\nO conteúdo do arquivo '%s' foi copiado\npara o arquivo '%s' com sucesso!", fileName, fileCopyName);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}