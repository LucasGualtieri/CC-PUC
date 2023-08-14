#include "biblioteca.h"

string decimalParaBin(float decVal) {
	string str = (string)malloc(50 * sizeof(char));

	// Convertendo a parte inteira.
	for (int i = decVal; i >= 1; i /= 2) {
		strcat(str, i % 2 == 0 ? "0" : "1");
	}

	// Invertendo a string.
	size_t len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char aux		 = str[i];
		str[i]			 = str[len - 1 - i];
		str[len - 1 - i] = aux;
	}

	// Convertendo a parte fracionária.
	int	  parteInteira	   = decVal;
	float parteFracionaria = decVal - parteInteira;

	if (parteFracionaria > 0) strcat(str, ".");

	for (int i = 0; i < 5; i++) {
		if ((parteFracionaria *= 2) > 1) {
			strcat(str, "1");
			parteFracionaria = parteFracionaria - (int)parteFracionaria;
		} else if (parteFracionaria == 1) {
			strcat(str, "1");
			i = 5;
		} else {
			strcat(str, "0");
		}
	}

	return str;
}

int main() {

	// Testes

	printf("ctoi('A'): %d\n", ctoi('A'));
	printf("ctoi('B'): %d\n", ctoi('B'));
	printf("ctoi('C'): %d\n", ctoi('C'));
	printf("ctoi('D'): %d\n", ctoi('D'));
	printf("ctoi('E'): %d\n", ctoi('E'));
	printf("ctoi('F'): %d\n", ctoi('F'));

	const char* hex = "AAF23";
	printf("atof(valor): %f\n", atof(hex));

	string str = decimalParaBin(240.1);

	printf("Res: %s\n", str);

	free(str);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}