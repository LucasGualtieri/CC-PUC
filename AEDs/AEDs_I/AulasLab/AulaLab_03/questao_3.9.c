#include <stdio.h>

void mostraMensagem(int index, char* nome, float novoSalario, int aumentos) {
	printf("\n");

	if (index == 5) {
		printf("Cargo: %s\n", nome);
		printf("Valor do aumento: %d%%\n", aumentos);
		printf("Não houve alteração no salário\n");
	} else {
		printf("Cargo: %s\n", nome);
		printf("Valor do aumento: %d%%\n", aumentos);
		printf("Novo salário: R$%.2f reais\n", novoSalario);
	}
}

int main() {
	int index;

	struct Cargos {
		int aumentos;
		char* nome;
		float salario;
	};

	struct Cargos cargos[5] = {
		{ 50, "Escriturário" },
		{ 35, "Secretário" },
		{ 20, "Caixa" },
		{ 10, "Gerente" },
		{ 0, "Diretor" }
	};

	printf("Cargos: \n1 - Escriturário\n2 - Secretário\n3 - Caixa\n4 - Gerente\n5 - Diretor\n");
	do {
		printf("\nCargo: ");
		scanf("%d", &index);
	} while (index < 1 || index > 5);
	index--;

	printf("Cargo Selecionado: (%s)\n", cargos[index].nome);
	printf("Salário: ");
	scanf("%f", &cargos[index].salario);

	cargos[index].salario += cargos[index].salario * (cargos[index].aumentos * 0.01);
	mostraMensagem(index, cargos[index].nome, cargos[index].salario, cargos[index].aumentos);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}