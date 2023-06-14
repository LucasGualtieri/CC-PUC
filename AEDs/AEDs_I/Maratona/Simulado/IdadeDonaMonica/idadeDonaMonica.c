#include <stdio.h>

int main(void) {
	int idadeDonaMonica, filho1, filho2, filho3, filhoMaisVelho = 0;

	scanf("%d", &idadeDonaMonica);
	scanf("%d", &filho1);
	scanf("%d", &filho2);

	filho3 = idadeDonaMonica - (filho1 + filho2);

	filhoMaisVelho = (filho1 > filho2) ? filho1 : filho2;
	if (filhoMaisVelho < filho3) filhoMaisVelho = filho3;

	printf("%d", filhoMaisVelho);

	return 0;
}