#include <stdio.h>

/*
	A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando
	dados sobre o salário e número de filhos de cada habitante.
	A prefeitura deseja saber:
	a) média do salário da população;
	b) média do número de filhos;
	c) maior salário;
	d) percentual de pessoas com salário até R$100,00.
	O final da leitura de dados se dará com a entrada de um salário negativo
*/

// clear && ./exercicio5 < pub.in > out.txt

int main() {
	float salario, salarioTotal = 0, maiorSalario = 0;
	float mediaSalario, mediafil;
	int qtdHabitantes = 0, filhos, qtdTotalFilhos = 0, salarioAte100 = 0;

	scanf("%f %d", &salario, &filhos);
	// printf("Salario: %.2f\n", salario);
	// printf("Filhos: %d\n", filhos);

	while (salario > 0) {

		qtdHabitantes++;

		// Media salario
		salarioTotal += salario;

		// Media filhos
		qtdTotalFilhos += filhos;

		// Maiorsalario
		if (salario > maiorSalario) {
			maiorSalario = salario;
		}

		if (salario <= 100.0) salarioAte100++;

		scanf("%f %d", &salario, &filhos);
	}

	mediaSalario = salarioTotal / qtdHabitantes;
	mediafil = qtdTotalFilhos / qtdHabitantes;

	if (salario < 0) {
		printf("%.2f\n", mediaSalario);
		printf("%.0f\n", mediafil);
		printf("%.2f\n", maiorSalario);
		printf("%.2f\n", (salarioAte100 * 100.0) / qtdHabitantes);
	}
	return 0;
}