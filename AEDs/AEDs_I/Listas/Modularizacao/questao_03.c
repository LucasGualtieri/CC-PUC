#include <stdio.h>

// Essa função recebe um número inteiro n e retorna ->
// o n-ésimo termo da sequência { 1/3, 1/5, 1/7, 1/9, 1/11, ... }
double UmSobreImpar(int n, int x) {
	int resultado = 1;

	for (int i = 0; i < n; i++) {
		resultado += 2;
	}

	return x == 1 ? 1 / (double)resultado : resultado;
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio03() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nO %d° termo da sequência é 1/%.0lf ou %.4lf", n, UmSobreImpar(n, 0), UmSobreImpar(n, 1));
}

int main() {

	Exercicio03();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}