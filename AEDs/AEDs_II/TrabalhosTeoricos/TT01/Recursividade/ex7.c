#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int isVowel(char c) {
	return strchr("aeiouAEIOU", c) ? 1 : 0;
}

int isLowerCasedConsonant(char c) {
	return (c <= 'B' || 'Z' <= c) && !isVowel(c) ? 1 : 0;
}

int lowerCasedCons(string str, int length) {

	if (length == 0) return 0;

	if (isLowerCasedConsonant(str[--length])) {
		return 1 + lowerCasedCons(str, length);
	} else {
		return lowerCasedCons(str, length);
	}
}

int main() {
	string str = strdup("AbCdEfGhIjK");

	printf("A string possui %d caracteres não vogais e não consoantes maiúsculas.\n ", lowerCasedCons(str, strlen(str)));

	free(str);
}