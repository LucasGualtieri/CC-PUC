#ifndef BIBLIOTECA_C_H_
#define BIBLIOTECA_C_H_

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

typedef char* String;

#define endl "\n"
#define AND &&
// #define and &&
#define OR ||
// #define or ||
#define MaxStringLength 2000

char flushStdin() {
	char c;
	while ((c = getchar()) != '\n' || c != EOF) { }
	return c;
}

// Pausa o código até o ENTER fecha o programa caso contrário
void pause(bool flush) {

	if (flush) flushStdin(); // Preciso flushar somente se não estiver limpo

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

// Confere se o CPF é válido ou não
// bool checkCPF(String cpf) {

// 	String cpfCopy = MaskCPF(cpf);

// 	int soma = 0;

// 	for (int i = 0, j = 10; j >= 2; i++) {
// 		if (cpfCopy[i] != '.' && cpfCopy[i] != '-') {
// 			soma += (cpfCopy[i] - '0') * j;
// 			j--;
// 		}
// 	}

// 	// Settando o primeiro dígito verificador
// 	if (soma % 11 < 2) {
// 		cpfCopy[cpfCopy.length() - 2] = '0';
// 	} else {
// 		sprintf(&cpfCopy[cpfCopy.length() - 2], "%d", 11 - (soma % 11));
// 	}

// 	soma = 0;

// 	for (int i = 0, j = 11; j >= 2; i++) {
// 		if (cpfCopy[i] != '.' && cpfCopy[i] != '-') {
// 			soma += (cpfCopy[i] - '0') * j;
// 			j--;
// 		}
// 	}

// 	// Settando o segundo dígito verificador
// 	if (soma % 11 < 2) {
// 		cpfCopy[cpfCopy.length() - 1] = '0';
// 	} else {
// 		sprintf(&cpfCopy[cpfCopy.length() - 1], "%d", 11 - (soma % 11));
// 	}

// 	// cout << cpfCopy << endl;
// 	// cout << cpf << endl;

// 	return cpfCopy == MaskCPF(cpf) ? true : false;
// }

// Retorna uma string com mascara a partir de um long int.
char* MaskCPF(unsigned long CPFNumber) {

	if (0) { // !checkCPF(CPFNumber);
		puts("CPF inválido!");
		// return NULL;
	}

	String CPF = (String)malloc(15 * sizeof(char));
	if (CPF == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in MaskCPF()\n");
		return NULL;
	}

	sprintf(CPF, "%ld", CPFNumber);

	char CPFCopy[15] = "000.000.000-00";

	// Apply mask
	for (int i = 0, j = 0; CPF[i] != '\0'; i++, j++) {
		if (CPF[i] == '.' || CPF[i] == '-') i++;
		if (j == 3 || j == 7 || j == 11) j++;
		CPFCopy[j] = CPF[i];
	}

	strcpy(CPF, CPFCopy);

	return CPF;

	/*
		There are a few potential issues with the code:

		The function takes a long argument, but a CPF number is usually represented as a 11-digit integer. The long data type may not be sufficient to represent all possible CPF numbers, as it has a maximum value of 2^63-1. It would be better to use an unsigned integer data type, such as unsigned long long.

		The code checks for an invalid CPF number using the expression if (0). This is always false and will never execute the code inside the block. It's unclear what the intention was here, but if the idea was to check for an invalid CPF number, a better approach would be to use the checkCPF function and return NULL if the number is invalid.

		The function allocates memory for a String object, which is not a standard C data type. It's possible that this is a custom data type defined elsewhere in the code, but without knowing its implementation it's hard to tell if this allocation is correct. It would be safer to use a standard C string (char*) instead.

		The function allocates memory for the CPF string, but it never frees that memory. This can lead to memory leaks if the function is called multiple times.

		The CPFCopy array is initialized to "000.000.000-00", which assumes that all CPF numbers have this format. However, CPF numbers are sometimes represented without the punctuation, so this may not always be the case. It would be better to initialize the array to all zeros and let the mask be applied dynamically based on the length of the input string.

		The function returns a pointer to the CPF string, which is allocated on the heap. This means that the caller of the function is responsible for freeing the memory when it's no longer needed. However, the caller may not be aware of this and may forget to free the memory, leading to memory leaks. A better approach would be to pass a pre-allocated buffer to the function, and have the function fill in that buffer with the masked CPF number. This way, the caller doesn't need to worry about memory management.
	*/
}

/*!
 * Retorna uma newline-terminated string.
 * @param file Pode ser substituido por stdin ou 0.
 */
char* getstr(FILE* file) {

	// Limpando o STDIN
	char c = getchar();
	if (c != '\n' && c != EOF) {
		ungetc(c, stdin);
	}

	if (file == 0) file = stdin;

	// Allocate memory for string
	char* string = (char*)malloc(MaxStringLength * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in getstr()\n");
		return NULL;
	}

	// Read string from file
	if (fgets(string, MaxStringLength, file) == NULL) {
		fprintf(stderr, "Error: Failed to read string from file in getstr()\n");
		free(string);
		return NULL;
	}

	// *string[len] == *(string[len])
	string[(int)strcspn(string, "\r\n")] = '\0';

	// Reallocate memory to exact size of string
	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
	if (string == NULL) {
		fprintf(stderr, "Error: Failed to reallocate memory in getstr()\n");
		return NULL;
	}

	return string;
}

/*!
 * Equivalente a um fgets, mas para char*.
 * @param string Endereço do char* (buffer) que a string será armazenada.
 * @param file Pode ser substituido por stdin.
 */
void fgetstr(char** string, FILE* file) {

	// Limpando o STDIN
	char c = getchar();
	if (c != '\n' OR c != EOF) {
		ungetc(c, stdin);
	}

	// Allocate memory for string
	*string = (char*)malloc(MaxStringLength * sizeof(char));
	if (*string == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in fgetstr()\n");
		return;
	}

	// Read string from file
	if (fgets(*string, MaxStringLength, file) == NULL) {
		fprintf(stderr, "Error: Failed to read string from file in fgetstr()\n");
		free(*string);
		*string = NULL;
		return;
	}

	// *string[len] == *(string[len])
	(*string)[(int)strcspn(*string, "\r\n")] = '\0';

	// Reallocate memory to exact size of string
	*string = (char*)realloc(*string, (strlen(*string) + 1) * sizeof(char));
	if (*string == NULL) {
		fprintf(stderr, "Error: Failed to reallocate memory in fgetstr()\n");
		return;
	}
}

char* readString(char* string) {
	printf("%s", string);
	return getstr(stdin);
}

// Pointer String Copy. Equivalente a um strcpy, mas para Pointer Strings. pstrcpy(&string, "New String");
void pstrcpy(char** strArg, char* string) {
	*strArg = (char*)realloc(*strArg, strlen(string) + 1 * sizeof(char));
	strcpy(*strArg, string);
}

// Pointer String Concat. Equivalente a um strcat, mas para Pointer Strings. pstrcat(&string, "New String");
char* pstrcat(char* source, char* append) {
	source = (char*)realloc(source, strlen(source) + strlen(append) + 1 * sizeof(char));
	return strcat(source, append);
}

// Create Pointer String. Cria um Pointer String a partir de um string hardcoded. createpstr(&string, "New String");
void createpstr(char** strArg, char* string) {
	*strArg = (char*)malloc((strlen(string) + 1) * sizeof(char));
	strcpy(*strArg, string);
}

char* substr(char* string, int beginning, int end) {
	if (end < 1) return string;

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

#endif /* BIBLIOTECA_C_H_ */
