#include <stdio.h>
#include <string.h>

int main() {

	int vetorIdade[] = { 18, 19, 20 }; // Vetor de inteiros

	char vetorCaracteres[] = { 'N', 'o', 'm', 'e' }; // Vetor de caracteres != string

	// Uma string é um vetor de caracters terminado em \0;
	char string[] = "12345"; // Aqui o \0 é adicionado ao fim implicitamente

	printf("Tamanho do vetor string: %d\n", (int)sizeof(string));
	printf("Tamanho da string: %d\n", (int)strlen(string)); // String length - Descarta o \0

	char nome[80];

	printf("Digite seu nome: ");
	// scanf("%[^\n]", nome);
	fgets(nome, sizeof(nome), stdin);
	printf("Nome: %s\n", nome);

	return 0;
}