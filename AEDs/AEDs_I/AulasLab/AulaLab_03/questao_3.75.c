#include <stdio.h>

void mostraMensagem(int codigo, char* cargos, float novoSalario, int aumentos) {
	if (codigo == 5) {
		printf("\nCargo: %s", cargos);
		printf("\nValor do aumento: %d%%", aumentos);
		printf("\nNão houve alteração no salário");
	} else {
		printf("\nCargo: %s", cargos);
		printf("\nValor do aumento: %d%%", aumentos);
		printf("\nNovo salário: R$%.2f reais", novoSalario);
	}
}

int main(void) {
	int codigo;
	float salario;
	int aumentos[] = { 50, 35, 20, 10, 0 };
	char* cargos[] = { "Escriturário", "Secretário", "Caixa", "Gerente", "Diretor" };
	// cargos[6]. precisa especificar o tamanho? Não precisa se tiver declarando os itens na inicialização.

	printf("\nCargos: \n1 - Escriturário\n2 - Secretário\n3 - Caixa\n4 - Gerente\n5 - Diretor\n");
	do {
		printf("\nCargo: ");
		scanf("%d", &codigo);
	} while (codigo < 1 || codigo > 5);

	// printf("Cargo Selecionado: (%s)\n", cargos[codigo]);
	printf("Salário: ");
	scanf("%f", &salario);

	for (int i = 0; i < 5; i++) {
		if (codigo - 1 == i) {
			salario += salario * (aumentos[i] * 0.01);
			mostraMensagem(codigo, cargos[i], salario, aumentos[i]);
			break;
		}
	}
	return 0;
}