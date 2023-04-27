#include <stdio.h>

int main(void) {
	int nota1, nota2, nota3, media, soma;

	scanf("%d %d %d", &nota1, &nota2, &nota3);

	soma = nota1 + nota2 + nota3;
	media = soma / 3;
	printf("A média é: %d", media);

	return 0;
}