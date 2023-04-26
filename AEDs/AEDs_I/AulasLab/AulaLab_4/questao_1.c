#include <stdio.h>

int main(void) {
	int anoAtual;
	float salario = 1000.00, aumento = 0.015;

	do {
		printf("\nDigite o ano atual (Não pode ser menor que 2005): ");
		scanf(" %d", &anoAtual);
	} while (anoAtual < 2005);

	int numberOfReps = anoAtual - 2005;

	for (int loop = 0; loop < numberOfReps; loop++, aumento *= 2) {
		salario += salario * aumento;
	}

	printf("Salario atualizado: %.2f", salario);

	return 0;
}