#include <stdbool.h>
#include <stdio.h>

int LerMes() {
	bool ERRO = false;
	int mes;

	printf("DIGITE MES[1/12]: ");
	do {
		if (ERRO) {
			puts("MES INVALIDO");
			printf("DIGITE MES VALIDO[1/12]: ");
		}
		scanf("%i", &mes);
		ERRO = (mes >= 13 || mes <= 0);
		// printf("Erro: %i", ERRO);

	} while (ERRO);

	return mes;
}

int arranjo(int vetor[12], int mesLido) {
	return vetor[mesLido - 1];
}

void escreva(int mesX) {
	printf("O MES TEM %i DIAS\n", mesX);
}

int main(void) {
	int vetor[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int mesLido = LerMes();

	int numeroDeDiasDoMesLido = arranjo(vetor, mesLido);

	escreva(numeroDeDiasDoMesLido);

	// escreva(arranjo(vetor, LerMes()));
	return 0;
}