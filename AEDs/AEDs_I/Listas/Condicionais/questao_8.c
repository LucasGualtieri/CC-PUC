#include <stdio.h>

int main(void) {
	int salario;
	char string;
	printf("A = Aumento de 8%% no salário. \nB = Aumento de 11%% no salário. \nC = Aumento fixo no salário\n");
	printf("\nDigite A, B ou C (minúsculo): ");
	scanf("%c", &string);
	printf("Digite o salário: ");
	scanf("%d", &salario);

	switch (string) {
	case 'a':
		salario += salario * 0.08;
		break;
	case 'b':
		salario += salario * 0.11;
		break;
	case 'c':
		if (salario <= 1000) {
			salario += 350;
		} else if (salario > 1000) {
			salario += 200;
		}
		break;
	}
	printf("\nSalário é: %d", salario);

	return 0;
}