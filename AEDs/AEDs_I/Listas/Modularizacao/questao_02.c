#include <stdio.h>

/*
	Essa função recebe um número inteiro n e retorna o
	n-ésimo termo da sequência { 2, 4, 6, 8, 10, 12... }
*/
int par(int n) {
	return n * 2;
}

/*
	Essa função recebe um número inteiro n e mostra na tela
	(em ordem decrescente) todos os valores menores do que
	par(n) para a sequência { 2, 4, 6, 8, 10, 12... }.
	Para n = 5 -> { 8, 6, 4, 2 }
*/
void MostrarParOrdemDecre(int n) {

	printf("\n{ ");
	for (int i = par(n - 1); i > 0; i -= 2) {
		printf("%d", i);
		printf("%s", (i > 2) ? ", " : " }");
	}
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio02() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	MostrarParOrdemDecre(n);
}

int main() {

	Exercicio02();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

/*
	// Alternativa
	void MostrarParOrdemDecre(int n) {

		int aux = Par(n);

		printf("\n{ ");
		for (int i = n; i > 0; i--) {
			int par = Par(i);
			if (par < aux) {
				printf("%d", par);
				printf("%s", (par > 2) ? ", " : " }");
			}
		}
	}
*/