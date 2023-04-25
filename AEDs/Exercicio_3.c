#include <stdio.h>

	/*
		Ler dois números reais e salva-los nas variáveis A e B. Em seguida, troque dos
		valores das duas variáveis de forma que a variável A passe a ter o valor da
		variável B e vice-versa. No final, mostre os valores finais.
	*/
	
	int main(void) {
	float a, b, c;
	printf("Digite 2 valores reais: ");
	scanf("%f %f", &a, &b);
	printf("\nA = %.2f\n", a);
	printf("B = %.2f\n", b);
	
	c = a;
	a = b;
	b = c;
	
	printf("\nApós a inversão:");
	printf("\nA = %.2f & B = %.2f", a, b);
	return 0;
}