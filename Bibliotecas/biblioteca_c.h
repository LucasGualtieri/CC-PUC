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

#define Infinity 2'147'483'647
#define arrayLength(array) (int)(sizeof(array) / sizeof(array[0]))
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

typedef char* String;

#define CPF unsigned long
#define endl "\n"
#define AND &&
// #define and &&
#define OR ||
// #define or ||
#define MaxStringLength 2'000
#define ends 2'000

// FlushStream
void flush(FILE* stream) {
	if (stream == 0) stream = stdin;
	char c;
	while ((c = fgetc(stream)) != '\n' && c != EOF) continue;
}

/*!
 * Pausa o programa até o usuario apertar ENTER.
 * O programa termina caso algo além de ENTER for digitado.
 * @param flush se == 1 limpará a entrada padrão.
 * @param flush se == 0 não limpará a entrada padrão.
 */
void Pause(bool flushing) {

	if (flushing) flush(stdin);

	printf("Paused | Press ENTER to continue...");

	if (getchar() != '\n') {
		printf("\n------- | PROGRAMA EXITADO | -------\n\n");
		exit(0);
	}
}

int strsize(char* string) {
	return strlen(string) + 1;
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
bool isPrime(int inteiro) {
	if (inteiro == 1) return false;
	for (int i = inteiro - 1; i > 1; i--) {
		if (inteiro % i == 0) return false;
	}
	return true;
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
		int aux	 = maxRange;
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
void SelectionSort(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		int swap	 = array[menor];
		array[menor] = array[i];
		array[i]	 = swap;
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

int indexOf(char* string, const char* reference, int occurrence) {

	for (int i = 0; i <= strlen(string) - strlen(reference); i++) {
		char* substring = substr(string, i, strlen(reference) + i);

		if (!strcmp(substring, reference)) {
			occurrence--;
			if (occurrence == 0) return i;
		}
	}
	return -1;
}

/*
		// Confere se o CPF é válido ou não
		bool checkCPF(String cpf) {

				String cpfCopy = MaskCPF(cpf);

				int soma = 0;

				for (int i = 0, j = 10; j >= 2; i++) {
						if (cpfCopy[i] != '.' && cpfCopy[i] != '-') {
								soma += (cpfCopy[i] - '0') * j;
								j--;
						}
				}

				// Settando o primeiro dígito verificador
				if (soma % 11 < 2) {
						// cpfCopy[cpfCopy.length() - 2] = '0';
				} else {
						// sprintf(&cpfCopy[cpfCopy.length() - 2], "%d", 11 - (soma % 11));
				}

				soma = 0;

				for (int i = 0, j = 11; j >= 2; i++) {
						if (cpfCopy[i] != '.' && cpfCopy[i] != '-') {
								soma += (cpfCopy[i] - '0') * j;
								j--;
						}
				}

				// Settando o segundo dígito verificador
				if (soma % 11 < 2) {
						// cpfCopy[cpfCopy.length() - 1] = '0';
				} else {
						// sprintf(&cpfCopy[cpfCopy.length() - 1], "%d", 11 - (soma % 11));
				}

				// cout << cpfCopy << endl;
				// cout << cpf << endl;

				return cpfCopy == MaskCPF(cpf) ? true : false;
		}
*/

// Retorna uma string com mascara a partir de um long int.
char* MaskCPF(unsigned long CPFNumber) {

	if (0) { // !checkCPF(CPFNumber);
		puts("CPF inválido!");
		// return NULL;
	}

	String cpf = (String)malloc(15 * sizeof(char));
	if (cpf == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in MaskCPF()\n");
		return NULL;
	}

	sprintf(cpf, "%ld", CPFNumber);

	char CPFCopy[15] = "000.000.000-00";

	// Apply mask
	for (int i = 0, j = 0; cpf[i] != '\0'; i++, j++) {
		if (cpf[i] == '.' || cpf[i] == '-') i++;
		if (j == 3 || j == 7 || j == 11) j++;
		CPFCopy[j] = cpf[i];
	}

	strcpy(cpf, CPFCopy);

	return cpf;

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

// Retorna uma ' '-terminated string.
char* trim(char* string) {

	int substringLength = indexOf(string, " ", 1);

	string[substringLength] = '\0';

	string = (char*)realloc(string, substringLength * sizeof(char));

	return string;
}

/*!
 * Retorna uma newline-terminated string.
 * @param file Pode ser substituido por stdin ou 0.
 * @param file Se igual a 0 Retorna uma newline-terminated string lida do stdin.
 */
char* getstr(FILE* stream) {

	if (stream == 0) stream = stdin;

	// Limpando o STDIN
	// flushStdin(stream); // Since I changed the logic to flushStdin()
	// it's not working as intended, maybe it'll be necessary to add a bool
	// flush just like the pause() function

	// Allocate memory for string
	char* string = (char*)malloc(MaxStringLength * sizeof(char));
	if (string == NULL) {
		fprintf(stdin, "Error: Failed to allocate memory in getstr()\n");
		return NULL;
	}

	// Reading string from file
	if (fgets(string, MaxStringLength, stream) == NULL) {
		fprintf(stdin, "Error: Failed to read string from file in getstr()\n");
		free(string);
		return NULL;
	}

	// *string[len] == *(string[len])
	string[(int)strcspn(string, "\r\n")] = '\0';

	// Reallocating memory to exact size of string
	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
	if (string == NULL) {
		fprintf(stdin, "Error: Failed to reallocate memory in getstr()\n");
		return NULL;
	}

	return string;
}

char* readString(char* string) {
	printf("%s", string);
	return getstr(stdin);
}

/*!
 * Malloca uma string em um buffer. strcopy(&buffer, newString)
 * @param buffer Endereço do buffer que a string será armazenada.
 * @param string String já mallocada que será .
 */
void strcopy(char** buffer, char* string) {

	if (*buffer != (void*)0x64) {
		free(*buffer);
	}

	*buffer = string;
}

// Pointer String Concat. Equivalente a um strcat, mas para Pointer Strings. pstrcat(&string, "New String");
char* pstrcat(char* source, char* append) {
	source = (char*)realloc(source, strlen(source) + strlen(append) + 1 * sizeof(char));
	return strcat(source, append);
}

// Create String. Cria um Pointer String a partir de um string hardcoded. createpstr(&string, "New String");
void mallocstr(char** strArg, char* string) {
	*strArg = (char*)malloc((strlen(string) + 1) * sizeof(char));
	strcpy(*strArg, string);
}

// Returns the length of a null terminated array of strings
int strArrayLen(String* listaAtual) {
	int i = 0;
	while (listaAtual[i++] != NULL) { }
	return i - 1;
}

// Frees every malloc'd string of a null terminated array of strings AND the buffer itself
void freeSplit(char** split) { // Better name? freeStringArray
	for (int i = 0; split[i] != NULL; i++) {
		free(split[i]);
	}
	free(split);
}

char** split(char* string, char* regex, bool freeBuffer) {
	char** array	   = NULL;
	int	   sizeOfArray = 0;

	char* position = string; // Track the position within the buffer

	while (true) {
		array = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));

		if (indexOf(position, regex, 1) != -1) {
			array[sizeOfArray] = (char*)malloc(indexOf(position, regex, 1) * sizeof(char));
			strcpy(array[sizeOfArray], substr(position, 0, indexOf(position, regex, 1)));
		} else {

			int sizeOfAllocation;
			if (sizeOfArray == 0) {
				sizeOfAllocation = strlen(string); //  Only string available
			} else {
				sizeOfAllocation = strlen(array[sizeOfArray - 1]); // Last string read
			}

			array[sizeOfArray] = (char*)malloc(sizeOfAllocation * sizeof(char));
			strcpy(array[sizeOfArray++], substr(position, 0, strlen(position)));

			break;
		}

		position += strlen(array[sizeOfArray++]) + 1;
	}

	array			   = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));
	array[sizeOfArray] = NULL;

	if (freeBuffer) free(string);

	return array;
}

char* replaceAll(char* string, char* regex, char* replacement) {
	char* aux = (char*)malloc(2'000 * sizeof(char));

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