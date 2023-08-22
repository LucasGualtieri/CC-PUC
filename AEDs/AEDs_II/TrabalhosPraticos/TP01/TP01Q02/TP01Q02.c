#include "../LibCTP01.h"

// clear && gcc TP01Q02.c -o TP01Q02 && ./TP01Q02 < pub.in > result.txt

/*
	"a�a"					- SIM
	"a��a"					- SIM
	"aça"					- SIM
	"açça"					- SIM
	"açaça"					- SIM
	"açéa"					- NAO // Esse está dando resultado errado
	"açéaaéça"				- SIM
	"açéaéça"				- SIM
	"marrocos - socorram" 	- SIM
*/

#define isSpecialChar(c) !(33 <= c && c <= 126)

bool isPalindromo(String str) {

	int left = -1, right = strlen(str);

	while (++left <= --right) {
		if (!isSpecialChar(str[left]) || !isSpecialChar(str[right])) {
			if (str[left] != str[right]) return false;
		}
	}

	return true;
}

int main() {
	char str[STR_MAX_LEN];
	while (!equals(readstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}
}