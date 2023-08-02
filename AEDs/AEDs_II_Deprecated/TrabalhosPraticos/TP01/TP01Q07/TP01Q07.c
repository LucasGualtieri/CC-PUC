#include <biblioteca_c.h>

bool soVogais(char* string) {
	int stringLength = strlen(string);

	for (int i = 0; string[i] != '\0'; i++) {
		if (strchr("aeiouAEIOU", string[i]) == NULL) {
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

	char* string = getstr(0);

	while (strcmp(string, "FIM")) {
		printf("%s ", soVogais(string) ? "SIM" : "NAO");
		printf("%s ", !soVogais(string) ? "SIM" : "NAO");
		// printf("%s ", isInt(string) ? "SIM" : "NAO");
		// printf("%s\n", isReal(string) ? "SIM" : "NAO");
		printf("\n");
		strcopy(&string, getstr(0));
	}

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}