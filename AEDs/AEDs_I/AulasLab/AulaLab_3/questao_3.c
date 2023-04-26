#include <stdio.h>

int main(void) {
	int codigo, salario, aumento, novoSalario;
	char* cargo;

	printf("Cargo: ");
	scanf("%d", &codigo);
	printf("\nSalário: ");
	scanf("%d", &salario);

	if (codigo == 1) {
		cargo = "Escriturário";
		aumento = 50;
		novoSalario = salario + (salario * 0.5);
	} else if (codigo == 2) {
		cargo = "Secretário";
		aumento = 35;
		novoSalario = salario + (salario * 0.35);
	} else if (codigo == 3) {
		cargo = "Caixa";
		aumento = 20;
		novoSalario = salario + (salario * 0.2);
	} else if (codigo == 4) {
		cargo = "Gerente";
		aumento = 10;
		novoSalario = salario + (salario * 0.1);
	} else if (codigo == 5) {
		cargo = "Diretor";
		aumento = 0;
	}

	if (codigo < 5 && codigo > 0) {
		printf("\nCargo: %s", cargo);
		printf("\nValor do aumento: %d%%", aumento);
		printf("\nNovo salário: %d reais", novoSalario);
	} else if (codigo == 5) {
		printf("\nCargo: %s", cargo);
		printf("\nValor do aumento: %d%%", aumento);
		printf("\nNão houve alteração no salário");
	} else {
		printf("\nCódigo inválido");
	}
	return 0;
}