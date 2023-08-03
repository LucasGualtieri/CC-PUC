#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc palindromo.c -o palindromo && ./palindromo < pub.in > alun.out

/*
	a�a                 - SIM
	a��a                - SIM
	aça                 - SIM
	açça                - SIM
	açaça               - SIM
	açéa                - NAO
	açéaaéça            - SIM
	açéaéça             - SIM
	marrocos - socorram - SIM
*/

#define STRING_MAX_LEN 500
#define SPECIAL_CHAR -61
#define UNKNOW_CHAR(value) ((value == -17 || value == -67) ? true : false)

typedef char* string;

bool isPalindromo(char* str) {

	int left = 0, right = strlen(str) - 1;

	while (left <= right) {

		if (str[left] != SPECIAL_CHAR && !UNKNOW_CHAR(str[left])) {
			if (str[left] != str[right]) return false;
		} else {
			if (!UNKNOW_CHAR(str[left])) {
				if (str[++left] != str[right--]) return false;
			} else {
				if (!UNKNOW_CHAR(str[right])) return false;
				left += 2, right -= 2;
			}
		}

		left++, right--;
	}

	return true;
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