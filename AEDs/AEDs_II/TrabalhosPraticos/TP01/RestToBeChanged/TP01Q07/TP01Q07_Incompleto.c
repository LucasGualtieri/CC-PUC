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

int main() {

	char* string = getstr();

	while (strcmp(string, "FIM")) {
		printf("%s ", soVogais(string) ? "SIM" : "NAO");
		printf("%s ", !soVogais(string) ? "SIM" : "NAO");
		// printf("%s ", isInt(string) ? "SIM" : "NAO");
		// printf("%s\n", isReal(string) ? "SIM" : "NAO");
		printf("\n");
		string = getstr();
	}

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}