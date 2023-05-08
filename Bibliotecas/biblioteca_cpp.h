#pragma once
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <string.h>
// #include <stdexcept>
// #include <exception>
#include <stdio.h>
#include <string>

#define Infinity 2147483647
#define arrayLength(array) (sizeof(array) / sizeof(array[0]))
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

#define MaxStringLength 2000

#define AND &&
// #define and &&
#define OR ||
// #define or ||

// typedef int lint; // Normal int -> 4 bytes
// #define int short // short or short int -> 2 bytes
// typedef long long llint; // long int or long long -> 8 bytes

using namespace std;

void pause(string String = "") {
	cout << "Paused " << String
		 << " | Press ENTER to continue...";

	// cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (cin.get() != '\n') {
		cout << "\n------- | PROGRAMA EXITADO | -------\n\n";
		exit(0);
	}
}

int readint(string _String = "") {
	int number;
	cout << _String;
	cin >> number;
	return number;
}

// Returns a random number, does not work wonderfully on windows.
int Rand(int maxRange = Infinity, int minRange = 0) {

	srand(time(NULL));

	if (minRange > maxRange) {
		int aux = maxRange;
		maxRange = minRange;
		minRange = aux;
	}

	return (rand() % ((maxRange + 1) - minRange)) + minRange;
}

// Char to Int
int ctoi(char _char) {
	return _char - '0'; // '0' == 48
}

// Returns 1 if number is prime.
int isPrime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

// ArrayPrint para inteiros
void ArrayPrint(int* array, int arrayLength) {
	cout << "{ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
		if (i == arrayLength - 1) {
			cout << " }" << endl;
			break;
		}
		cout << ", ";
	}
}

// ArrayPrint para float
void ArrayPrint(float* array, int arrayLength) {
	cout << "{ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
		if (i == arrayLength - 1) {
			cout << " }" << endl;
			break;
		}
		cout << ", ";
	}
}

// ArrayPrint para char
void ArrayPrint(char* array, int arrayLength) {
	cout << "{ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
		if (i == arrayLength - 1) {
			cout << " }" << endl;
			break;
		}
		cout << ", ";
	}
}

// ArrayPrint para strings
void ArrayPrint(string* array, int arrayLength) {
	cout << "{ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
		if (i == arrayLength - 1) {
			cout << " }" << endl;
			break;
		}
		cout << ", ";
	}
}

// --------------------------------------------------------------

// ArrayFillRand para inteiros
void ArrayFillRand(int* array, int arrayLength, int maxRange, int minRange = 0) {
	// cout << "Inteiro" << endl;
	// Inverte os valores max e min para quando apenas um {arg} for passado.
	int min_range = minRange;
	if (minRange > maxRange) {
		min_range = maxRange;
		maxRange = minRange;
	}

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (rand() % ((maxRange + 1) - min_range)) + min_range;
		srand(rand());
		// printf("%d ", array[i]);
	}
}

// ArrayFillRand para Float
void ArrayFillRand(float* array, int arrayLength, int maxRange, int minRange = 0) {
	// cout << "Float" << endl;
	// Inverte os valores max e min para quando apenas um arg for passado.
	int min_range = minRange;
	if (minRange > maxRange) {
		min_range = maxRange;
		maxRange = minRange;
	}

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (rand() % ((maxRange + 1) - min_range)) + min_range;
		srand(rand());
		// printf("%d ", array[i]);
	}
}

// --------------------------------------------------------------

// vetorCrescente para inteiros
void vetorCrescente(int* array, int arrayLength) {
	int index;
	int arrayCopy[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		int smallestArrayVal = Infinity;
		for (int j = 0; j < arrayLength; j++) {
			if (array[j] < smallestArrayVal) {
				smallestArrayVal = array[j];
				index = j;
			}
		}
		array[index] = Infinity;
		arrayCopy[i] = smallestArrayVal;
	}

	for (int i = 0; i < arrayLength; i++) {
		array[i] = arrayCopy[i];
		// printf("%d \n", array[i]);
	}
}

// vetorCrescente para Float
void vetorCrescente(float* array, int arrayLength) {
	int index;
	float arrayCopy[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		int smallestArrayVal = Infinity;
		for (int j = 0; j < arrayLength; j++) {
			if (array[j] < smallestArrayVal) {
				smallestArrayVal = array[j];
				index = j;
			}
		}
		array[index] = Infinity;
		arrayCopy[i] = smallestArrayVal;
	}

	for (int i = 0; i < arrayLength; i++) {
		array[i] = arrayCopy[i];
		// printf("%d \n", array[i]);
	}
}

// Array in Ascending Int
void ArrayAscendingOrder(int* array, int arrayLength) {
	int a;
	for (int i = 0; i < arrayLength; i++) {
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[i] > array[j]) {
				a = array[i];
				array[i] = array[j];
				array[j] = a;
			}
		}
	}
}

// Array in Ascending Order Float
void ArrayAscendingOrder(float* array, int arrayLength) {
	float a;
	for (int i = 0; i < arrayLength; i++) {
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[i] > array[j]) {
				a = array[i];
				array[i] = array[j];
				array[j] = a;
			}
		}
	}
}

// --------------------------------------------------------------

// Mascara a string CPF, caso não tenha mascara, e não mascara caso tenha.
string maskTelefone(long int telefone) {
	string strTelefone = to_string(telefone);

	strTelefone.insert(0, 1, '(');
	strTelefone.insert(3, 1, ')');
	strTelefone.insert(9, 1, '-');

	return strTelefone;
}

string MaskCPF(string CPF) {
	string CPFCopy = "000.000.000-00";

	for (int i = 0, j = 0; CPF[i] != '\0'; i++, j++) {
		if (CPF[i] == '.' || CPF[i] == '-') i++;
		if (j == 3 || j == 7 || j == 11) j++;
		CPFCopy[j] = CPF[i];
	}

	return CPFCopy;
}

// Confere se o CPF é válido ou não
bool checkCPF(string cpf) {

	string cpfCopy = MaskCPF(cpf);

	int soma = 0;

	for (int i = 0, j = 10; j >= 2; i++) {
		if (cpfCopy[i] != '.' && cpfCopy[i] != '-') {
			soma += (cpfCopy[i] - '0') * j;
			j--;
		}
	}

	// Settando o primeiro dígito verificador
	if (soma % 11 < 2) {
		cpfCopy[cpfCopy.length() - 2] = '0';
	} else {
		sprintf(&cpfCopy[cpfCopy.length() - 2], "%d", 11 - (soma % 11));
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
		cpfCopy[cpfCopy.length() - 1] = '0';
	} else {
		sprintf(&cpfCopy[cpfCopy.length() - 1], "%d", 11 - (soma % 11));
	}

	// cout << cpfCopy << endl;
	// cout << cpf << endl;

	return cpfCopy == MaskCPF(cpf) ? true : false;
}

// Mascara a string Date, caso não tenha mascara, e não mascara caso tenha.
string MaskDate(string date) {
	string dateCopy = "dd/mm/aaaa";

	for (int i = 0, j = 0; date[i] != '\0'; i++, j++) {
		if (date[i] == '/') i++;
		if (j == 2 || j == 5) j++;
		dateCopy[j] = date[i];
	}

	return dateCopy;
}

// Mascara a string CEP, caso não tenha mascara, e não mascara caso tenha.
string MaskCep(string cep) {
	string cepCopy = "00000-000";

	for (int i = 0, j = 0; cep[i] != '\0'; i++, j++) {
		if (cep[i] == '-') i++;
		if (j == 5) j++;
		cepCopy[j] = cep[i];
	}

	return cepCopy;
}

void flushStdin(FILE* stream) {

	int c = fgetc(stream);

	if (c != '\n' && c != EOF) {
		ungetc(c, stream);
	}
}

char* getstr(FILE* stream) {

	if (stream == 0) stream = stdin;

	// Limpando o STDIN
	flushStdin(stream);

	// Allocate memory for string
	char* str = (char*)malloc(MaxStringLength * sizeof(char));
	if (str == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory in getstr()\n");
		return NULL;
	}

	// Reading string from file
	if (fgets(str, MaxStringLength, stream) == NULL) {
		fprintf(stderr, "Error: Failed to read string from file in getstr()\n");
		free(str);
		return NULL;
	}

	// *string[len] == *(string[len])
	str[(int)strcspn(str, "\r\n")] = '\0';

	// Reallocating memory to exact size of string
	str = (char*)realloc(str, (strlen(str) + 1) * sizeof(char));
	if (str == NULL) {
		fprintf(stderr, "Error: Failed to reallocate memory in getstr()\n");
		return NULL;
	}

	return str;
}

#endif /* BIBLIOTECA_H_ */