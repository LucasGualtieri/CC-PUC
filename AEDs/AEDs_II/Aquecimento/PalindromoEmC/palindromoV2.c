#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX_LEN 150

typedef char* string;

// clear && gcc palindromo.c -o palindromo && ./palindromo < pub.in > alun.out

bool isSpecialChar(char c) { return !(isalnum(c) || c == ' ' || c == '-'); }

bool isPalindromo(string str) {

	string copy = strdup(str);

	for (int i = 0; i < strlen(str); i++) {
		if (!isSpecialChar(str[i])) {
			copy[i] = str[strlen(str) - 1 - i];
		}
	}

	bool result = !strcmp(str, copy);

	free(copy);

	return result;
}

int main() {

	string str = (string)malloc(STRING_MAX_LEN * sizeof(char));

	scanf("%[^\r\n]", str);

	while (strcmp(str, "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
		scanf(" %[^\r\n]", str);
	}

	free(str);

	return 0;
}