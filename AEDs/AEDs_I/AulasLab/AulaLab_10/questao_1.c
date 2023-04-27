#include <stdio.h>
#include <string.h>

/*
	Faça um algoritmo para percorrer uma
	string e imprimir apenas as vogais.
*/

int main() {
	char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'A' || str[i] == 'a' ||
			str[i] == 'E' || str[i] == 'e' ||
			str[i] == 'I' || str[i] == 'i' ||
			str[i] == 'O' || str[i] == 'o' ||
			str[i] == 'U' || str[i] == 'u') {
			printf("%c", str[i]);
		}
	}
	
	return 0;
}