#include <stdio.h>

int main() {

	char letra;

	printf("Digite um caractere: "), scanf("%c", &letra);

	// Você gostaria que eu tivesse usado a tabela ASCII né?
	// Estrutura condicional que testa o tipo de caractere.
	if (letra >= 'A' && letra <= 'Z') {
		printf("Maiúscula");
	} else if (letra >= 'a' && letra <= 'z') {
		printf("Minúscula");
	} else if (letra >= '0' && letra <= '9') {
		printf("Dígito");
	} else {
		printf("Outro caractere");
	}

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}