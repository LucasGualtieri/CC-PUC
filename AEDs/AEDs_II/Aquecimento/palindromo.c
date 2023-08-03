#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STRING_MAX_LEN 50
#define UNKNOWN_CHAR_BEG -17
#define UNKNOWN_CHAR_END -67

typedef char* string;

// clear && gcc palindromoFunc.c -o palindromoFunc && ./palindromoFunc < pub.in > alun.out

bool isSpecialChar(char c) {
	return !(isalnum(c) || c == ' ' || c == '-');
}

bool isPalindromo(char* str) {

	int left = 0, right = strlen(str) - 1;

	while (left <= right) {

		if (str[left] == UNKNOWN_CHAR_BEG) {
			if (str[right] != UNKNOWN_CHAR_END) return false;
			left += 2, right -= 2;
		} else if (isSpecialChar(str[left])) {
			if (str[left++] != str[--right]) return false;
		} else {
			if (str[left++] != str[right--]) return false;
		}
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