#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define bool short
#define TRUE 1
#define true 1
#define FALSE 0
#define false 0

#define equals(a, b) !strcmp(a, b) ? true : false
#define STR_MAX_LEN 400
#define toUpper(c) ('a' <= c && c <= 'z') ? c - 32 : c
#define isalnum(c) ('1' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')

typedef char* String;

size_t strlen(const char* str) {
	int len = 0;
	while (str[len++] != 0);
	return len - 1;
}

bool isEqual(const char* str1, const char* str2) {
	size_t len;
	if ((len = strlen(str1)) != strlen(str2)) return false;

	bool isEqual = true;

	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) {
			isEqual = false;
			i		= len;
		}
	}

	return isEqual;
}

int indexOf(String str, char c) {
	int len = strlen(str) + 1;
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == c) len = i;
	}

	return len;
}

float getFloat(FILE* stream) {
	if (!stream) stream = stdin;
	float floatValue;
	fscanf(stream, "%f", &floatValue);
	// flush();
	return floatValue;
}

int getInt(FILE* stream) {
	if (!stream) stream = stdin;
	int integer;
	fscanf(stream, "%d", &integer);
	return integer;
}

// clear && gcc TP01Q02wChar.c -o TP01Q02wChar && ./TP01Q02wChar < pub.in > result.txt

/*
	"a�a"					- SIM
	"a��a"					- SIM
	"a�a�a"					- SIM
	"a´b´a"					- SIM
	"a´b`a"					- NAO
	"aça"					- SIM
	"açça"					- SIM
	"açaça"					- SIM
	"açéa"					- NAO
	"açéaaéça"				- SIM
	"açéaéça"				- SIM
	"marrocos - socorram" 	- SIM
*/

#define STR_MAX_LEN 400
#define SPECIAL_CHAR -61 // characteres especias (e.g., ç, á, à, ã, etc)
#define isSingleChar(c) (c > 0)

typedef wchar_t* wString;
typedef wchar_t wChar;

wString readstr(wString str) {
	fgetws(str, STR_MAX_LEN, stdin);
	str[wcslen(str) - 1] = '\0';
	return str;
}

/*
	- Retorna true ou false se a palavra é ou não um palíndromo.
	- Faço isso testando as extremidades da palavra até chegar no meio da palavra.
	- Em C, os caracteres são representados com apenas 1 byte,
	ao contrário de Java, que utiliza 2 bytes. Isso faz com
	que caracteres especiais (por exemplo, ç, á, à, ã, etc.)
	sejam representados por DOIS SUBCARACTERES. Sendo assim,
	certas manipulações especiais são necessárias para determinar
	se a palavra é ou não um palíndromo.
*/
bool isPalindromo(wString string) {
	bool result = true;
	int len = wcslen(string) - 1;
	for (int i = 0; i < len; i++) {
		if (string[i] != string[len - i]) {
			i = len;
			result = false;
		}
	}
	return result;
}

int main() {

	wString str[STR_MAX_LEN];

	while (!isEqual(readstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}

	return 0;
}