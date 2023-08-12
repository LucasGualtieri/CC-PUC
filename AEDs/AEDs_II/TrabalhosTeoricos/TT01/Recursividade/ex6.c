#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int isVowel(char c) {
	return strchr("aeiouAEIOU", c) ? 1 : 0;
}

int vowelsCount(string str, int length) {

	if (length == 0) return 0;

	if (isVowel(str[--length])) {
		return 1 + vowelsCount(str, length);
	} else {
		return vowelsCount(str, length);
	}
}

int main() {
	string str = strdup("ABCDEFGHIJK");

	printf("A string possui %d vogais.\n", vowelsCount(str, strlen(str)));

	free(str);
}