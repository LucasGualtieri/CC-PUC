#include <stdio.h>
#include <stdlib.h>

// Por algum motivo não fiz essa, esse código foi copiado da solução

int main(void) {

	int quant, num;
	int i, j;
	int fat = 1;

	printf(" Digite a quantidade de valores que devems ser lidos a seguir : ");
	scanf("%d", &quant);

	for (i = 1; i <= quant; i++) {
		printf(" Digite um numero : ");
		scanf("%d", &num);
		for (j = 1; j <= num; j++) {
			fat = fat * j;
		}
		printf(" Seu fatorial : %d \n\n", fat);
		fat = 1;
		// No fim do loop a variavel fat deve receber 1 novamente senao ela vai
		// utilizar o valor do fatorial anterior para calcular os demais.
	}

	return (0);
}