#include <stdio.h>

int main(void) {
	int anoNascimento, idade;
	int anoAtual = 2022;
	char resposta;

	printf("Digite o seu ano de nascimento: ");
	scanf("%d", &anoNascimento);

	printf("Já fez aniversário no ano atual? S ou N: ");
	scanf(" %c", &resposta);

	while (!(resposta == 'S' || resposta == 's' || resposta == 'N' || resposta == 'n')) {
		// printf("A reposta tem que ser 'S' ou 'N'\n");
		printf("Já fez aniversário no ano atual? S ou N: ");
		scanf(" %c", &resposta);
	}

	if (resposta == 'S' || resposta == 's') {
		idade = anoAtual - anoNascimento;
		printf("Idade é %d\n", idade);
		if (idade >= 18) {
			printf("Já tem idade para conseguir Carteira de Habilitação");
		} else {
			printf("Não tem idade para conseguir Carteira de Habilitação");
		}
	} else if (resposta == 'N' || resposta == 'n') {
		idade = anoAtual - anoNascimento - 1;
		printf("Idade é %d\n", idade);
		if (idade >= 18) {
			printf("Já tem idade para conseguir Carteira de Habilitação");
		} else {
			printf("Não tem idade para conseguir Carteira de Habilitação");
		}
	}
}