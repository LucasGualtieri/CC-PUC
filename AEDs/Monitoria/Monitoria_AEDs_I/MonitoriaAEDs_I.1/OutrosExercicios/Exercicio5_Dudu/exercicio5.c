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

int main() {

	// declaração
	float sal, somasal = 0, maiorsal = 0, mediasal, mediafilho, percsal100;
	int filho, somafilho = 0, hab = 0, sal100 = 0;

	scanf("%f", &sal);
	scanf("%d", &filho);

	while (sal > 0) {

		somasal += sal;
		somafilho += filho;
		hab++;

		if (sal > maiorsal) {
			maiorsal = sal;
		}
		if (sal <= 100 && sal > 0) {
			sal100++;
		}

		scanf("%f", &sal);
		scanf("%d", &filho);
	}

	mediasal = somasal / hab;
	mediafilho = somafilho / hab;
	percsal100 = ((float)sal100 / hab) * 100;

	printf("%.2f\n", mediasal);
	printf("%.0f\n", mediafilho);
	printf("%.2f\n", maiorsal);
	printf("%.2f\n", percsal100);

	// printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}