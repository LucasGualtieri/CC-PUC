#include <stdio.h>

int main(void) {
	int number;
	printf("Número inteiro de 3 dígitos: ");
  	scanf("%d", &number);

  	int c = number / 100;
  	int d = (number % 100) / 10;
  	int u = number % 10;
  	// printf("C: %d\n", c);
  	// printf("D: %d\n", d);
  	// printf("U: %d\n", u);

	int reverse = ((u * 100) + (d * 10) + c);
  	printf("\nNúmero Invertido: %d", reverse);
  	return 0;
}
