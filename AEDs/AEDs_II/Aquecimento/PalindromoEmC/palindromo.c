#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc palindromo.c -o palindromo && ./palindromo < pub.in > alun.out

/*
	"a�a"					- SIM
	"a��a"					- SIM
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
#define isSingleChar(c) (isalnum(c) || c == ' ' || c == '-')

typedef char* string;

string getstr(string str) {
	fgets(str, STR_MAX_LEN, stdin);
	str[strcspn(str, "\r\n")] = '\0';
	return str;
}

bool isPalindromo(string str) {

	int left = -1, right = strlen(str);

	while (left++ <= right--) {
		// Conferindo caracteres Alphanuméricos.
		if (isSingleChar(str[left])) {
			if (str[left] != str[right]) return false;
		} else {
			// Conferindo characteres especias (e.g., ç, á, à, ã, etc).
			int scLen = (str[left] == SPECIAL_CHAR) ? 1 : 2; // Special Character Length
			if (str[left + scLen] != str[right]) return false;
			left += scLen, right -= scLen;
		}
	}

	return true;
}

int main() {

	char str[STR_MAX_LEN];

	while (strcmp(getstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}

	return 0;
}