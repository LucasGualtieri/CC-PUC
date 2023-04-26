#include <stdio.h>

int main(void) {
	int nota1, nota2, nota3, media;
	
	scanf("%d %d %d", &nota1, &nota2, &nota3);
	
	media = (nota1 + nota2 + nota3) / 3;
	printf("A média é: %d", media);
	
	return 0;
}