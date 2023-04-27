#include <stdio.h>

int main(void) {
	char input;

	printf("Digite qualquer caractere: ");
	scanf("%c", &input);

	switch (input) {
	case '<':
		printf("Sinal de MENOR");
		break;
	case '>':
		printf("Sinal de MAIOR");
		break;
	case '=':
		printf("Sinal de IGUAL");
		break;
	default:
		printf("Outro sinal");
	}

	return 0;
}