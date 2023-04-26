#ifndef BIBLIOTECA_C_H_
#define BIBLIOTECA_C_H_

// Comentário Teste

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <windows.h>

#define Infinity 2147483647
#define arrayLength(array) (int)(sizeof(array) / sizeof(array[0]))
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

#define String char*

#define endl "\n"
#define AND &&
// #define and &&
#define OR ||
// #define or ||

// Pausa o código até o ENTER fecha o programa caso contrário
void pause() {
	// Tenho que arrumar uma forma de clear o stdin
	printf("Paused | Press ENTER to continue...");

	if (getchar() != '\n') {
		printf("\n------- | PROGRAMA EXITADO | -------\n\n");
		exit(0);
	}
}

char toLower(char c) {
	if (c >= 'A' AND c <= 'Z') return c += 32;
	return c;
}

void toUpper(char* string) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] >= 'a' AND string[i] <= 'z') {
			string[i] -= 32;
		}
	}
}

// Returns 1 if number is prime.
int isPrime(int n) {
	if (n == 1) return 0;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}

	return 1;
}

// arrayPrint para inteiros
void IntArrayPrint(int* array, int arrayLength) {
	printf("{ ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
		printf("%s", i < arrayLength - 1 ? ", " : " }\n");
	}
}

// ArrayFillRand para Inteiros - Linux
void IntArrayFillRand(int* array, int arrayLength, int minRange, int maxRange) {

	if (minRange > maxRange) {
		int aux = maxRange;
		maxRange = minRange;
		minRange = aux;
	}

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = RANDOM(minRange, maxRange);
	}
}

// ArrayFillRand para Inteiros - Windows
// void IntArrayFillRand(int* array, int arrayLength, int minRange, int maxRange) {

// 	srand(time(NULL));
// 	srand(rand());
// 	for (int i = 0; i < arrayLength; i++) {
// 		array[i] = (rand() % ((maxRange + 1) - minRange)) + minRange;
// 		srand(rand());
// 		// printf("%d ", array[i]);
// 	}
// }

// Selection Sort para Inteiros em ordem Crescente
void selectionSort(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		int swap = array[menor];
		array[menor] = array[i];
		array[i] = swap;
	}
}

// Mascara a string CPF, caso não tenha mascara, e não mascara caso tenha.
void MaskCPF(char* CPF) {
	char CPFCopy[15] = "000.000.000-00";

	for (int i = 0, j = 0; CPF[i] != '\0'; i++, j++) {
		if (CPF[i] == '.' || CPF[i] == '-') i++;
		if (j == 3 || j == 7 || j == 11) j++;
		CPFCopy[j] = CPF[i];
	}

	strcpy(CPF, CPFCopy);
}

// Get Pointer String. Equivalente a um scanf mas para char*. Ótimo para strings em structs - getsptr(&p1.nome);
void pscanf(char** string) {
	*string = (char*)malloc(2000 * sizeof(char));
	if (*string == NULL) printf("Falha na alocação de memória: Função 'pscanf'.\n");

	fgets(*string, 2000, stdin);
	*string[strcspn(*string, "\r\n")] = '\0';

	*string = (char*)realloc(*string, (strlen(*string) + 1) * sizeof(char));
	if (*string == NULL) printf("Falha na alocação de memória: Função 'pscanf'.\n");
}

char* getstr() {

	const size_t maxStringLength = 2000;

	// Limpando o STDIN
	char c = getchar();
	if (c != '\n') {
		ungetc(c, stdin);
	}

	char* string = (char*)malloc(maxStringLength * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "getstr - malloc error");
		return NULL;
	}

	if ((fgets(string, maxStringLength, stdin)) == NULL) {
		fprintf(stderr, "getstr - fgets error");
		return NULL;
	}

	string[strcspn(string, "\r\n")] = '\0';

	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "getstr - realloc error");
		return NULL;
	}

	/*
		A função strcspn() é usada para determinar o comprimento
		da sequência inicial da string que não contém nenhum dos
		caracteres especificados em sua segunda entrada (neste caso, "\r\n").
		Isso permite que a função determine a posição do primeiro
		caractere de nova linha na string, para que ele possa ser
		substituído pelo caractere nulo. -Chat GPT
	*/

	return string;
}

char* readString(char* string) {
	printf("%s", string);
	return getstr();
}

// File Get Pointer String. Equivalente a um fscanf mas para char*. Ótimo para strings em structs - fgetsptr(&string, file);
void fgetsptr(char** string, FILE* file) {
	*string = (char*)malloc(2000 * sizeof(char));
	if (*string == NULL) printf("Falha na alocação de memória: Função 'fgetsptr'.\n");

	fgets(*string, 2000, file);
	*string[strcspn(*string, "\r\n")] = '\0';

	*string = (char*)realloc(*string, (strlen(*string) + 1) * sizeof(char));
	if (string == NULL) printf("Falha na alocação de memória: Função 'fgetsptr'.\n");
}

// Pointer String Copy. Equivalente a um strcpy, mas para Pointer Strings. pstrcpy(&string, "New String");
void pstrcpy(char** strArg, char* string) {
	*strArg = (char*)realloc(*strArg, strlen(string) + 1 * sizeof(char));
	strcpy(*strArg, string);
}

// Pointer String Concat. Equivalente a um strcat, mas para Pointer Strings. pstrcat(&string, "New String");
void pstrcat(char** strArg, char* string) {
	*strArg = (char*)realloc(*strArg, strlen(*strArg) + strlen(string) + 1 * sizeof(char));
	strcat(*strArg, string);
}

// Create Pointer String. Cria um Pointer String a partir de um string hardcoded. createpstr(&string, "New String");
void createpstr(char** strArg, char* string) {
	*strArg = (char*)malloc((strlen(string) + 1) * sizeof(char));
	strcpy(*strArg, string);
}

char* substr(char* string, int beginning, int end) {
	int length = end - beginning;

	char* strAux = (char*)malloc((length + 1) * sizeof(char));

	for (int i = 0; i < length; i++) {
		strAux[i] = string[beginning++];
	}

	strAux[length] = '\0';

	return strAux;
}

int indexOf(char* string, char* reference) {

	for (int i = 0; i <= strlen(string) - strlen(reference); i++) {
		char* substring = substr(string, i, strlen(reference) + i);

		if (!strcmp(substring, reference)) {
			return i;
		}
	}
	return -1;
}

char** split(char* string, char* regex) {
	char** array = NULL;
	int sizeOfArray = 0;

	while (true) {
		array = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));
		if (indexOf(string, regex) != -1) {
			array[sizeOfArray] = (char*)malloc(indexOf(string, regex) * sizeof(char));
			strcpy(array[sizeOfArray], substr(string, 0, indexOf(string, regex)));
		} else {
			array[sizeOfArray] = (char*)malloc(strlen(array[sizeOfArray - 1]) * sizeof(char));
			strcpy(array[sizeOfArray++], substr(string, 0, strlen(string)));
			break;
		}
		string += strlen(array[sizeOfArray++]) + 1;
	}

	return array;
}

char* replaceAll(char* string, char* regex, char* replacement) {
	char* aux = (char*)malloc(2000 * sizeof(char));

	for (int i = 0, j = 0; i < strlen(string);) {
		if (!strcmp(substr(string, i, strlen(regex) + i), regex)) {
			strcat(aux, replacement);
			j += strlen(replacement);
			i += strlen(regex);
		} else {
			aux[j] = string[i];
			j++;
			i++;
		}
	}

	aux[strlen(aux) + 1] = '\0';

	return (char*)realloc(aux, (strlen(aux) + 1) * sizeof(char));
}

/*
	// char* substr(char* string, int beggining, int end) {
	// 	int length = end - beggining;
	// 	char* aux = (char*)malloc((length + 1) * sizeof(char));

	// 	for (int i = 0; i < length; i++) {
	// 		aux[i] = string[beggining + i];
	// 	}

	// 	aux[length] = '\0';

	// 	return aux;
	// }

	// int indexOf(char* string, char* reference) {

	// 	for (int i = 0; i <= strlen(string) - strlen(reference); i++) {
	// 		char* substring = substr(string, i, strlen(reference) + i);

	// 		if (!strcmp(substring, reference)) {
	// 			return i;
	// 		}
	// 	}
	// 	return -1;
	// }

	// char** split(char* string, char* regex) {
	// 	int arraySize = 1;

	// 	// Descobrindo o tamanho do nosso Array
	// 	for (int i = 0; i < strlen(string) - strlen(regex); i++) {
	// 		if (!strcmp(substr(string, i, i + strlen(regex)), regex)) {
	// 			arraySize++;
	// 		}
	// 	}

	// 	// Criando o array de strings
	// 	char** array = (char**)malloc(arraySize * sizeof(char**));

	// 	// Separando as substrings e atribuindo
	// 	for (int i = 0; i < arraySize - 1; i++) {
	// 		array[i] = (char*)malloc((indexOf(string, regex) - 1) * sizeof(char*));
	// 		strcpy(array[i], substr(string, 0, indexOf(string, regex)));
	// 		string += indexOf(string, regex) + strlen(regex);
	// 	}
	// 	array[arraySize - 1] = (char*)malloc((strlen(string) - 1) * sizeof(char*));
	// 	strcpy(array[arraySize - 1], substr(string, 0, strlen(string)));

	// 	return array;
	// }

	// char** split(char* string, char* regex) {

	// 	// Criando o array de strings
	// 	char** array = (char**)malloc(30 * sizeof(char**));

	// 	int arraySize = 1;
	// 	// Separando as substrings e atribuindo
	// 	for (int i = 0; indexOf(string, regex) != strlen(string); i++, arraySize++) {
	// 		array[i] = (char*)malloc((indexOf(string, regex) - 1) * sizeof(char));
	// 		strcpy(array[i], substr(string, 0, indexOf(string, regex)));
	// 		string += indexOf(string, regex) + strlen(regex);
	// 	}

	// 	array[arraySize - 1]++;

	// 	return (char**)realloc(array, arraySize * sizeof(char**));
	// }

	// char** split(char* string, char* regex) {
	// 	// Criando o array de strings
	// 	char** array = (char**)malloc(50 * sizeof(char**));

	// 	// Separando as substrings e atribuindo
	// 	int i;
	// 	for (i = 0; indexOf(string, regex) != -1; i++) {
	// 		array[i] = (char*)malloc((indexOf(string, regex) - 1) * sizeof(char*));
	// 		strcpy(array[i], substr(string, 0, indexOf(string, regex)));
	// 		string += indexOf(string, regex) + 1;
	// 		array[i + 1] = (char*)malloc((strlen(string) - 1) * sizeof(char*));
	// 		strcpy(array[i + 1], substr(string, 0, strlen(string)));
	// 	}

	// 	return (char**)realloc(array, i + 1 * sizeof(char*));
	// }
*/

#endif /* BIBLIOTECA_C_H_ */
