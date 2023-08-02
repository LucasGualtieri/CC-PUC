#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindromo(char* str) {
	int left = 0, right = strlen(str) - 1;

	while (left <= right) {
		if (str[left++] != str[right--]) return false;
	}

	return true;
}

int main() {

	char str[50];

	scanf("%[^\n\r]%*c", str);

	while (strcmp(str, "FIM")) {
		printf("%s", isPalindromo(str) ? "SIM" : "NAO");
		scanf("%[^\n\r]%*c", str);
	}

	printf("FIM DO PROGRAMA");
	return 0;
}