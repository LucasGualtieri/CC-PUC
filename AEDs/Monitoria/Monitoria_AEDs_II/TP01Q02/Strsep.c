#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// clear && gcc Strsep.c && ./a.out

void main() {
	char string[] = "Lucas;;Gualtieri;Firace";
	char* aux = string;

	char nome[50];
	char segundoNome[50];
	char terceiroNome[50];
	char ultimonome[50];

	strcpy(nome, strsep(&aux, ";"));
	char* temp = strsep(&aux, ";");
	strcpy(segundoNome, !strcmp(temp, "") ? "vazio" : temp);
	strcpy(terceiroNome, strsep(&aux, ";"));
	strcpy(ultimonome, strsep(&aux, ";"));

	printf("Nome: '%s'\n", nome);
	printf("segundoNome: '%s'\n", segundoNome);
	printf("terceiroNome: '%s'\n", terceiroNome);
	printf("Ultimonome: '%s'\n", ultimonome);

}