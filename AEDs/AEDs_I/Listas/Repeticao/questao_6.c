#include <stdio.h>
#include <string.h> //Se não chamado, strlen() é declarado implicitamente;

int main() {

	char palavra[80];
	int key;

	printf("Digite uma palavra para ser criptografada: ");
	scanf("%s", palavra);

	printf("Digite a chave: ");
	scanf("%d", &key);

	// Adiciona Key ao valor de cada letra de uma palavra. Para { Key = 2 -> 'A' + key = C }
	for (int i = 0; i < strlen(palavra); i++) {
		printf("%c", palavra[i] + key);
	}

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}