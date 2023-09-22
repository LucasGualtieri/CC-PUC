#include <stdio.h>
#include <string.h>

void entradaporteclado() {
	int numaluno;
	char numeroTelefone[11];
	FILE* saida = fopen("saida.txt", "w");

	scanf("%d %s", &numaluno, numeroTelefone);
	while (1) {
		fprintf(saida, "%d %s\n", numaluno, numeroTelefone);
		scanf("%d", &numaluno);
		if (numaluno == -1) break;
		scanf("%s", numeroTelefone);
	}
}

void entradaporarquivo() {
	int numaluno;
	char numeroTelefone[11];
	FILE *entrada, *saida;

	entrada = fopen("entrada.txt", "r");
	saida = fopen("saida.txt", "w");

	while (!feof(entrada)) {

		fscanf(entrada, "%d", &numaluno);
		fscanf(entrada, "%s", numeroTelefone);

		fprintf(saida, "%d %s\n", numaluno, numeroTelefone);
	}
}

int main(void) {

	int opcao;

	printf("1- ler do console para que termine digite FIM\n");
	printf("2- ler de um arquivo (.txt)\n");
	printf("Digite qual das opções você gostaria de fazer uso\n");

	scanf("%d", &opcao);

	switch (opcao) {
	case 1:
		entradaporteclado();
		break;
	case 2:
		entradaporarquivo();
		break;
	default:
		printf("ERRO\n");
		break;
	}

	return 0;
}