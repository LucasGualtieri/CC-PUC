#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;
#define MaxStringLength 2000
#define ends 2000

// clear && gcc trinca.c -lm -I /home/lucas/CC-PUC/Bibliotecas -o trinca.exe && ./trinca.exe < pub.in > out.txt
// clear && gcc trinca.c -lm -o trinca.exe && ./trinca.exe < pub.in > out.txt

char* getstr(FILE* stream);
int stringsArrayLen(String* listaAtual);
void freeStringArray(String* arrayOfStrings);
char** split(char* string, char* regex, bool freeBuffer);
char* substr(char* string, int beginning, int end);
int indexOf(char* string, char* reference, int occurrence);
bool flushStdin(FILE* stream);

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
	freeSplit(listaAtual);
	freeSplit(listaNova);

	return 0;
}

bool flushStdin(FILE* stream) {

	// scanf("%d%*c", &idade);

	int c = fgetc(stream);

	if (c != '\n' && c != EOF) {
		ungetc(c, stream);
	}
}

char* substr(char* string, int beginning, int end) {
	if (end < 1) return string;

	if (end == ends) end = strlen(string);

	int length = end - beginning;

	static char strAux[MaxStringLength];
	// char* strAux = (char*)malloc((length + 1) * sizeof(char));

	for (int i = 0; i < length; i++) {
		strAux[i] = string[beginning++];
	}

	strAux[length] = '\0';

	return strAux;
}

int indexOf(char* string, char* reference, int occurrence) {

	for (int i = 0; i <= strlen(string) - strlen(reference); i++) {
		char* substring = substr(string, i, strlen(reference) + i);

		if (!strcmp(substring, reference)) {
			occurrence--;
			if (occurrence == 0) return i;
		}
	}
	return -1;
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
void freeSplit(char** split) {
	for (int i = 0; split[i] != NULL; i++) {
		free(split[i]);
	}
	free(split);
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