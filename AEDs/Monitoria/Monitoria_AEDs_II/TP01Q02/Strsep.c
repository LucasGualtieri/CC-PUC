#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
	// strdup foi necessário para o funcionamento do strdsep
	// char* string = strdup("Lucas;;Gualtieri;Firace");
	char* string = strdup("Lucas;;Gualtieri;Firace"); // Maloca
	// const char string[] = "Lucas Gualtieri Firace";

	char nome[50];
	char segundoNome[50];
	char terceiroNome[50];
	char ultimonome[50];

	strcpy(nome, strsep(&string, ";"));
	char* temp = strsep(&string, ";");
	strcpy(segundoNome, !strcmp(temp, "") ? "vazio" : temp);
	strcpy(terceiroNome, strsep(&string, ";"));
	strcpy(ultimonome, strsep(&string, ";"));

	printf("Nome: '%s'\n", nome);
	printf("segundoNome: '%s'\n", segundoNome);
	printf("terceiroNome: '%s'\n", terceiroNome);
	printf("Ultimonome: '%s'\n", ultimonome);

	free(string);

}