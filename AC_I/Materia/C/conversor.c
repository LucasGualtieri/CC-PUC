#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define AND &&
#define and &&
#define OR ||
#define or ||

int intConvert(char string) {
	if (string >= 'a' and string <= 'f' or string >= 'A' and string <= 'F') {
		switch (string) {
		case 'a':
			return 10;
		case 'A':
			return 10;
		case 'b':
			return 11;
		case 'B':
			return 11;
		case 'c':
			return 12;
		case 'C':
			return 12;
		case 'd':
			return 13;
		case 'D':
			return 13;
		case 'e':
			return 14;
		case 'E':
			return 14;
		default:
			return 15;
		}
	} else {
		return string - '0';
	}
}

int convertToDecimal(char* string, int base) {

	int numeroConvertido = 0;

	for (int i = strlen(string) - 1, exp = 0; i >= 0; i--, exp++) {
		numeroConvertido += intConvert(string[i]) * pow(base, exp);
	}

	return numeroConvertido;
}

int convertFromDecimal(int numeroDecimal, int base) {

	int auxNum, printNum, size = 0;

	auxNum = numeroDecimal;
	printNum = numeroDecimal;

	// Setta o size da array.
	while (auxNum > 0) {
		if (auxNum % base == 0) {
			auxNum /= base;
		} else {
			auxNum = (auxNum - 1) / base;
		}
		size++;
	}

	// Escreve os valores 0 ou 1 dentro de um vetor.
	int array[size];
	for (int i = 0; i < size; i++) {
		if (numeroDecimal % base == 0) {
			numeroDecimal /= base;
			array[i] = 0;
		} else {
			numeroDecimal = (numeroDecimal - 1) / base;
			array[i] = 1;
		}
	}

	printf("Binário de %d é: ", printNum);

	// Printa o vetor de trás pra frente;
	for (int loop = size - 1; loop >= 0; loop--) {
		printf("%d", array[loop]);
	}
}

int main() {
	SetConsoleOutputCP(65001);

	char* string = malloc(1);
	int numeroDecimal;

	printf("Digite um número: ");
	// scanf("%s", string);
	scanf("%d", numeroDecimal);

	// printf("%d\n", convertToDecimal(string, 2));
	printf("%d\n", convertFromDecimal(numeroDecimal, 2));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}