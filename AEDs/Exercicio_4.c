#include <stdio.h>
#include <math.h>

// Ler 3 numeros reais a, b e c e mostrar o valor de y sendo y = a + b/(c+a) + 2
// *(a-b) + log2(64).
int main(void) {
	float a, b, c, y;
	
	printf("Digite três números reais: ");
	scanf("%f %f %f", &a, &b, &c);
	
	y = (a + b) / (c + a) + 2 * (a - b) + log2(64);
	
	printf("A = %.2f B = %.2f C = %.2f Y = %.2f", a, b, c, y);
	return 0;
}