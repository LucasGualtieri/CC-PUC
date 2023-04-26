#include <stdio.h>
#include <string.h>

int main(void) {
	char palavra[80];
	int key;

	printf("Digite uma palavra para ser criptografada: ");
	scanf("%s", palavra);

	printf("Digite a chave: ");
	scanf("%d", &key);

	int length = strlen(palavra);
	for (int i = 0; i < length; i++) {
		printf("%c", palavra[i] += key);
	}

	// printf("\n********* Fim do programa *********");
	return 0;
}