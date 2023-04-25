#include <stdio.h>

int numeroInvertido(int number) {
	int c = number / 100;
	int d = (number % 100) / 10;
	int u = number % 10;
	
	return (u * 100) + (d * 10) + c;
}

int main(void) {
	int number;
	printf("Número inteiro de 3 dígitos: ");
	scanf("%d", &number);
	
	int reverse = numeroInvertido(number);
	printf("\nNúmero Invertido: %d", reverse);
	// printf("\nNúmero Invertido: %d", numeroInvertido(number)); // Forma alternativa de
	// fazer sem criar a variável reverse
	return 0;
}