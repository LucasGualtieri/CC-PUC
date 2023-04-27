#include <stdio.h>

int codigo, salario, aumento, novoSalario;
char* cargo;

void mostraMensagem(char* cargo, int aumento, float salario) {
	printf("\nCargo: %s", cargo);
	printf("\nValor do aumento: %d%%", aumento);
	printf("\nNovo salário: %d reais", novoSalario);
}

void logica(char* cargoFunc, int aumentoFunc, float salarioPercentual) {
	cargo = cargoFunc;
	aumento = aumentoFunc;
	novoSalario = salario + (salario * salarioPercentual);
}

int main(void) {

	printf("1- Escriturário | 2- Secretário | 3- Caixa | 4- Gerente | 5- Diretor\n");
	printf("Cargo: ");
	scanf("%d", &codigo);
	printf("\nSalário: ");
	scanf("%d", &salario);

	switch (codigo) {
	case 1:
		logica("Escriturário", 50, 0.5);
		mostraMensagem(cargo, aumento, novoSalario);
		break;
	case 2:
		logica("Secretário", 35, 0.35);
		mostraMensagem(cargo, aumento, novoSalario);
		break;
	case 3:
		logica("Caixa", 20, 0.2);
		mostraMensagem(cargo, aumento, novoSalario);
		break;
	case 4:
		logica("Gerente", 10, 0.1);
		mostraMensagem(cargo, aumento, novoSalario);
		break;
	case 5:
		logica("Diretor", 0, 0);
		mostraMensagem(cargo, aumento, novoSalario);
		break;
	default:
		printf("\nCódigo inválido");
	}

	return 0;
}