// #pragma once
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <chrono>
#include <ctime>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <string>
#include <thread>
#include <vector>
// #include <stdexcept>
// #include <exception>
// #include <biblioteca_c.h>

#define extends public
#define herda public

#define Infinity 2'147'483'647
#define arrayLength(array) (sizeof(array) / sizeof(array[0]))
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

#define MaxStringLength 2'000

#define AND &&
// #define and &&
#define OR ||
// #define or ||

// typedef int lint; // Normal int -> 4 bytes
// #define int short // short or short int -> 2 bytes
// typedef long long llint; // long int or long long -> 8 bytes

#define RED (string) "\x1b[31m"
#define GREEN (string) "\x1b[32m"
#define YELLOW (string) "\x1b[33m"
#define BLUE (string) "\x1b[34m"
#define MAGENTA (string) "\x1b[35m"
#define CYAN (string) "\x1b[36m"
#define RESET (string) "\x1b[0m"
#define BOLD (string) "\033[1m"

using namespace std;

void printColorLn(string msg, string color = RESET) {
	cout << color << msg << RESET << endl;
}

void printColor(string msg, string color = RESET) {
	cout << color << msg << RESET;
}

void printColorBold(string msg, string color = RESET) {
	cout << color << BOLD << msg << RESET;
}
void printColorBoldLn(string msg, string color = RESET) {
	cout << color << BOLD << msg << RESET << endl;
}

void clrscreen() {
	system("clear");
}

void flush() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause(string String = "") {
	cout << "Paused";
	cout << (String.length() > 0 ? " " : "");
	cout << String << " | Press ENTER to continue...";

	// flush();

	if (cin.get() != '\n') {
		cout << "\n------- | PROGRAMA EXITADO | -------\n\n";
		exit(0);
	}
}

void trim(string& str, char trim = ' ') {

	for (int i = 0; str.at(0) == trim; i++) {
		str.erase(0, 1);
	}

	for (int i = str.length() - 1; str.at(i) == trim; i--) {
		str.erase(i, 1);
	}
}

// The ideia is to replace a substring with a string like:
// "Lucas Gualtieri" - Substr: "cas" - Replace: "Michael Jackson" -> "LuMichael Jackson Gualtieri"
// "Lucas Gualtieri" - Substr: "cas" - Replace: "" -> "Lu Gualtieri"
// "Lucas Gualtieri" - Substr: "cas" - Replace: "sac" -> "Lusac Gualtieri"
// To be developed
void ReplaceSubstr(string& str, string substr, string replace);

void ReplaceAll(string& str, string change, string replace) {
	for (int i = 0; i < change.length(); i++) {
		char charToChange = change.at(i);
		for (int j = 0; j < str.length(); j++) {
			if (str.at(j) == charToChange) {
				str.erase(j, 1);
				str.insert(j, replace);
				j += replace.length();
			}
		}
	}
}

string readString(string msg = "", istream& stream = cin) {

	cout << msg;

	string aux;

	try {

		getline(stream, aux);

		size_t pos = aux.find_first_of("\r\n");

		if (pos != string::npos) aux.erase(pos);

	} catch (const ios_base::failure ex) {
		cerr << "Error reading input: " << ex.what() << endl;
	}

	return aux;
}

string readString(istream& stream = cin, string msg = "") {

	cout << msg;

	string aux;

	try {

		getline(stream, aux);

		size_t pos = aux.find_first_of("\r\n");

		if (pos != string::npos) aux.erase(pos);

	} catch (const ios_base::failure ex) {
		cerr << "Error reading input: " << ex.what() << endl;
	}

	return aux;
}

int readInt(string msg = "", string errorMsg = "DEFAULT") {

	if (errorMsg == "DEFAULT") {
		errorMsg = RED + "Invalid input, " + RESET + "try again: ";
	}

	cout << msg;

	bool invalid = false;
	int	 integer;

	do {
		if (invalid) {
			cout << errorMsg;
			std::cin.clear();
			flush();
		}
		cin >> integer;
	} while ((invalid = cin.fail()));

	flush();

	return integer;
}

int readFloat(string msg = "", string errorMsg = "DEFAULT") {

	if (errorMsg == "DEFAULT") {
		errorMsg = RED + "Invalid input, " + RESET + "try again: ";
	}

	cout << msg;

	bool invalid = false;
	int	 floatValue;

	do {
		if (invalid) {
			cout << errorMsg;
			std::cin.clear();
			flush();
		}
		cin >> floatValue;
	} while ((invalid = cin.fail()));

	flush();

	return floatValue;
}

// int readInt() {
// 	string aux;
// 	getline(cin, aux);

// 	size_t pos = aux.find_first_of("\r\n");

// 	if (pos != string::npos) {
// 		aux[pos] = '\0';
// 		aux.resize(pos + 1);
// 	}

// 	return stoi(aux);
// }

// Returns a random number, does not work wonderfully on windows.
int Rand(int maxRange = Infinity, int minRange = 0) {

	srand(time(NULL));

	if (minRange > maxRange) {
		int aux	 = maxRange;
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
		maxRange  = minRange;
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
		maxRange  = minRange;
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
				index			 = j;
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
	int	  index;
	float arrayCopy[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		int smallestArrayVal = Infinity;
		for (int j = 0; j < arrayLength; j++) {
			if (array[j] < smallestArrayVal) {
				smallestArrayVal = array[j];
				index			 = j;
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
				a		 = array[i];
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
				a		 = array[i];
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

// void flushStdin(FILE* stream) {

// 	int c = fgetc(stream);

// 	if (c != '\n' && c != EOF) {
// 		ungetc(c, stream);
// 	}
// }

char* substr(char* string, int beginning, int end) {

	const int ends = 2'000;

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

#endif /* BIBLIOTECA_H_ */