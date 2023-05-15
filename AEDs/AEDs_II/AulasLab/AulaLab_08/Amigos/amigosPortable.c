#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* String;

// clear && gcc trinca.c -lm -I /home/lucas/CC-PUC/Bibliotecas -o trinca.exe && ./trinca.exe < pub.in > out.txt
// clear && gcc trinca.c -lm -o trinca.exe && ./trinca.exe < pub.in > out.txt

void printLista(String* lista, String character) {
	int listaLength = stringsArrayLen(lista);
	for (int i = 0; i < listaLength; i++) {
		printf("%s%s", lista[i], i < listaLength - 1 ? " " : character);
	}
}

int main() {

	String* listaAtual = split(getstr(0), " ", 1);
	String* listaNova = split(getstr(0), " ", 1);
	String amigo = getstr(0);

	if (strcmp(amigo, "Nao")) {
		char** position = listaAtual;
		for (int i = 0; strcmp(listaAtual[i], amigo); i++) {
			printf("%s ", listaAtual[i]);
			position++;
		}

		printLista(listaNova, " ");

		printLista(position, "\n");

	} else {
		printLista(listaAtual, " ");
		printLista(listaNova, "\n");
	}

	free(amigo);
	freeStringArray(listaAtual);
	freeStringArray(listaNova);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

char* getstr(FILE* stream) {

	if (stream == 0) stream = stdin;

	// Limpando o STDIN
	flushStdin(stream);

	// Allocate memory for string
	char* string = (char*)malloc(MaxStringLength * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in getstr()\n");
		return NULL;
	}

	// Reading string from file
	if (fgets(string, MaxStringLength, stream) == NULL) {
		fprintf(stderr, "Error: Failed to read string from file in getstr()\n");
		free(string);
		return NULL;
	}

	// *string[len] == *(string[len])
	string[(int)strcspn(string, "\r\n")] = '\0';

	// Reallocating memory to exact size of string
	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "Error: Failed to reallocate memory in getstr()\n");
		return NULL;
	}

	return string;
}

// Returns the length of a null terminated array of strings
int stringsArrayLen(String* listaAtual) {
	int i;
	for (i = 0; listaAtual[i] != NULL; i++) { }
	return i;
}

// Frees every string of a null terminated array of strings
void freeStringArray(String* arrayOfStrings) {
	for (int i = 0; i < stringsArrayLen(arrayOfStrings); i++) {
		free(arrayOfStrings[i]);
	}
}

char** split(char* string, char* regex, bool freeBuffer) {
	char** array = NULL;
	int sizeOfArray = 0;

	char* position = string; // Track the position within the buffer

	while (true) {
		array = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));

		if (indexOf(position, regex, 1) != -1) {
			array[sizeOfArray] = (char*)malloc(indexOf(position, regex, 1) * sizeof(char));
			strcpy(array[sizeOfArray], substr(position, 0, indexOf(position, regex, 1)));
		} else {
			array[sizeOfArray] = (char*)malloc(strlen(array[sizeOfArray - 1]) * sizeof(char));
			strcpy(array[sizeOfArray++], substr(position, 0, strlen(position)));
			break;
		}

		position += strlen(array[sizeOfArray++]) + 1;
	}

	array = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));
	array[sizeOfArray] = NULL;

	if (freeBuffer) free(string);

	return array;
}