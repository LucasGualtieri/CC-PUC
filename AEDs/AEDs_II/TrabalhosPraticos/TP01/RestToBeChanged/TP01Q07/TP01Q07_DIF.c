#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool X1(char* s) {
	char vogais[] = "aeiouAEIOU";
	for (int i = 0; s[i] != '\0'; i++) {
		if (!strchr(vogais, s[i])) {
			return false;
		}
	}
	return true;
}

bool X2(char* s) {
	char consoantes[] = "bcdfghjklmnpqrstvwxyzçBCDFGHJKLMNPQRSTVWXYZÇ";
	for (int i = 0; s[i] != '\0'; i++) {
		if (!strchr(consoantes, s[i])) {
			return false;
		}
	}
	return true;
}

bool X3(char* s) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

bool X4(char* s) {
	bool ponto_encontrado = false;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '.') {
			if (ponto_encontrado) { // já encontrou um ponto anteriormente
				return false;
			} else { // primeiro ponto encontrado
				ponto_encontrado = true;
			}
		} else if (!isdigit(s[i])) { // não é dígito nem ponto
			return false;
		}
	}
	return true;
}

int main() {

	char str[1000];

	while (1) {
		// gets(str);
		scanf(" %[^\n]", str);
		if (!strcmp(str, "FIM")) {
			break;
		}

		if (X1(str)) {
			printf("SIM ");
		} else {
			printf("NAO ");
		}

		if (X2(str)) {
			printf("SIM ");
		} else {
			printf("NAO ");
		}

		if (X3(str)) {
			printf("SIM ");
		} else {
			printf("NAO ");
		}

		if (X4(str)) {
			printf("SIM ");
		} else {
			printf("NAO ");
		}

		printf("\n");
	}

	return 0;
}