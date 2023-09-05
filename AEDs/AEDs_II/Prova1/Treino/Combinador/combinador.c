#include <stdio.h>
#include <string.h>

// clear && gcc combinador.c && ./a.out

#define STR_MAX_LEN 50 + 1

int main() {

	char string00[STR_MAX_LEN];

	while (scanf(" %[^\n]", string00)) {
		char* string01 = strtok(string00, " ");
		char* string02 = strtok(NULL, " ");
		char* stringMaior, *stringMenor;

		// printf("string01: %s\n", string01);
		// printf("string02: %s\n", string02);

		int string01Len = strlen(string01);
		int string02Len = strlen(string02);
		int menorLen, maiorLen;

		if (string01Len > string02Len) {
			stringMaior = string01;
			stringMenor = string02;
			maiorLen = string01Len;
			menorLen = string02Len;
		} else {
			stringMaior = string02;
			stringMenor = string01;
			maiorLen = string02Len;
			menorLen = string01Len;
		}

		int i;
		for (i = 0; i < menorLen + maiorLen; i += 2) {
			string00[i] = stringMaior[i];
			if (i < menorLen) {
				string00[i + 1] = stringMenor[i];		
			}
			string00[i + 2] = 0;
			printf("string00: %s\n", string00);
		}
		string00[i - 1] = 0;

		printf("%s\n", string00);

	}
}